#ifndef CONTACT_H
#define CONTACT_H

#include <QString>

class Contact {
public:
    // Constructor
    Contact(const QString &name = "", const QString &phone = "", const QString &email = "");

    // Getter
    QString getName() const;
    QString getPhone() const;
    QString getEmail() const;

    // Setter
    void setName(const QString &name);
    void setPhone(const QString &phone);
    void setEmail(const QString &email);

private:
    // member variables
    QString m_name;
    QString m_phone;
    QString m_email;
};

#endif
