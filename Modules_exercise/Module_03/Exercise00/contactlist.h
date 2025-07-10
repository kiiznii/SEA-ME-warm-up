#ifndef CONTACTLIST_H
#define CONTACTLIST_H

#include "contact.h"
#include <QVector>

// 연락처 목록 클래스
class ContactList {
public:
    void addContact(const Contact &contact);     // 연락처 추가
    void removeContact(int index);    // 연락처 삭제
    const QVector<Contact>& getContacts() const; // 전체 목록 반환
    QVector<Contact> search(const QString &query) const;
private:
    QVector<Contact> m_contacts;  // 연락처들을 저장할 QVector
};

#endif
