#ifndef HUGGINGFACEAPI_H
#define HUGGINGFACEAPI_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class HuggingFaceAPI : public QObject {
    Q_OBJECT
public:
    explicit HuggingFaceAPI(QObject *parent = nullptr);

    // This function sends a text generation request to the Hugging Face API.
    Q_INVOKABLE void generateText(const QString &prompt);

signals:
    // Emitted when a result is ready (the raw JSON response as a string).
    void resultReady(const QString &result);
    // Emitted if an error occurs.
    void errorOccurred(const QString &error);

private slots:
    void onNetworkReplyFinished(QNetworkReply *reply);

private:
    QNetworkAccessManager m_manager;
    QString m_apiToken;
};

#endif // HUGGINGFACEAPI_H
