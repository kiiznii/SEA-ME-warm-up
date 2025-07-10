#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTableWidgetItem>
#include <QDebug>  // 디버깅용

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 버튼 클릭 시 슬롯 연결
    connect(ui->addButton, &QPushButton::clicked, this, &MainWindow::ADD);
    connect(ui->removeButton, &QPushButton::clicked, this, &MainWindow::REMOVE);
    connect(ui->searchButton, &QPushButton::clicked, this, &MainWindow::SEARCH);

    // 초기 테이블 표시 (이름만)
    updateTable(contactList.getContacts(), false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// 연락처 추가 함수
void MainWindow::ADD()
{
    QString name = ui->nameEdit->text();
    QString phone = ui->numberEdit->text();
    QString email = ui->emailEdit->text();

    if (name.isEmpty()) return;  // 이름은 필수

    Contact newContact(name, phone, email);
    contactList.addContact(newContact);

    // 이름만 보여주기
    updateTable(contactList.getContacts(), false);

    // 입력창 초기화
    ui->nameEdit->clear();
    ui->numberEdit->clear();
    ui->emailEdit->clear();
}

// 연락처 삭제 함수
void MainWindow::REMOVE()
{
    int row = ui->tableWidget->currentRow();
    if (row >= 0) {
        contactList.removeContact(row);
        updateTable(contactList.getContacts(), false);  // 이름만 다시 출력
    }
}

// 연락처 검색 함수
void MainWindow::SEARCH()
{
    QString query = ui->searchEdit->text().trimmed();

    if (query.isEmpty()) {
        updateTable(contactList.getContacts(), false);  // 검색어 없으면 전체 목록 (이름만)
    } else {
        QVector<Contact> results = contactList.search(query);
        updateTable(results, true);  // 검색 시 전체 정보 출력
    }
    ui->searchEdit->clear();
}

// 테이블 갱신 함수 (showDetails=true면 전화번호, 이메일 포함)
void MainWindow::updateTable(const QVector<Contact> &contacts, bool showDetails)
{
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(contacts.size());

    if (showDetails) {
        ui->tableWidget->setColumnCount(3);
        ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Name" << "Phone" << "Email");
    } else {
        ui->tableWidget->setColumnCount(1);
        ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Name");
    }

    for (int i = 0; i < contacts.size(); ++i) {
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(contacts[i].getName()));
        if (showDetails) {
            ui->tableWidget->setItem(i, 1, new QTableWidgetItem(contacts[i].getPhone()));
            ui->tableWidget->setItem(i, 2, new QTableWidgetItem(contacts[i].getEmail()));
        }
    }
}
