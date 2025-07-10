#include "contactlist.h"

// 연락처 추가 함수
void ContactList::addContact(const Contact &contact) {
    m_contacts.append(contact);
}

// 연락처 삭제 함수 (인덱스로 제거)
void ContactList::removeContact(int index) {
    if (index >= 0 && index < m_contacts.size())
        m_contacts.removeAt(index);
}

QVector<Contact> ContactList::search(const QString &query) const {
    QVector<Contact> result;
    for (const Contact &c : m_contacts) {
        if (c.getName().contains(query, Qt::CaseInsensitive) ||
            c.getPhone().contains(query, Qt::CaseInsensitive) ||
            c.getEmail().contains(query, Qt::CaseInsensitive)) {
            result.append(c);
        }
    }
    return result;
}

// 연락처 전체 리스트 반환
const QVector<Contact>& ContactList::getContacts() const {
    return m_contacts;
}
