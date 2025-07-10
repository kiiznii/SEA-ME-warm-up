// mainwindow.h - 메인 GUI 클래스 헤더

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "contactlist.h"  // 연락처 목록 포함

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

// MainWindow 클래스 선언
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr); // 생성자
    ~MainWindow();                          // 소멸자

private slots:
    void ADD();     // 추가 버튼 클릭 시 호출
    void REMOVE();    // 삭제 버튼 클릭 시 호출
    void SEARCH();
private:
    Ui::MainWindow *ui;             // 자동 생성된 UI 객체
    ContactList contactList;        // 연락처 목록 관리 클래스
    void updateTable(const QVector<Contact> &contacts, bool showDetails);             // 테이블 UI 갱신 함수
};

#endif // MAINWINDOW_H
