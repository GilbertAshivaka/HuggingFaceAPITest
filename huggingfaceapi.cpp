#include "HuggingFaceAPI.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QUrl>
#include <QNetworkRequest>
#include <QDebug>

HuggingFaceAPI::HuggingFaceAPI(QObject *parent)
    : QObject(parent)
{
    //obtain API key from HugingFace
    m_apiToken = ""; 

    // Connect the finished signal so that any reply is handled.
    connect(&m_manager, &QNetworkAccessManager::finished,
            this, &HuggingFaceAPI::onNetworkReplyFinished);
}

void HuggingFaceAPI::generateText(const QString &prompt)
{
    // Define the model endpoint URL.
    QUrl url("https://api-inference.huggingface.co/models/google/gemma-2-2b-it");
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("Authorization", QString("Bearer %1").arg(m_apiToken).toUtf8());

    // Create the JSON payload.
    QJsonObject json;
    json["inputs"] = prompt;
    QJsonDocument doc(json);
    QByteArray data = doc.toJson();

    // Send the POST request.
    m_manager.post(request, data);
}

void HuggingFaceAPI::onNetworkReplyFinished(QNetworkReply *reply)
{
    if (reply->error() != QNetworkReply::NoError) {
        QString errorString = reply->errorString();
        emit errorOccurred(errorString);
        reply->deleteLater();
        return;
    }

    QByteArray responseData = reply->readAll();
    QJsonDocument responseDoc = QJsonDocument::fromJson(responseData);

    QString cleanedResponse;

    if (responseDoc.isArray()) {
        QJsonArray jsonArray = responseDoc.array();
        if (!jsonArray.isEmpty()) {
            QString generatedText = jsonArray[0].toObject()["generated_text"].toString();

            // Clean up the text (replace \n with real line breaks)
            cleanedResponse = generatedText.replace("\\n", "\n");
        }
    }

    if (cleanedResponse.isEmpty()) {
        cleanedResponse = "No valid response from the model.";
    }

    emit resultReady(cleanedResponse);
    reply->deleteLater();
}
