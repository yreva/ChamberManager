#include "InputDialog.h"

InputDialog::InputDialog(QWidget *parent) : QDialog(parent) {
    lineEdit = new QLineEdit;

    QPushButton *okButton = new QPushButton(tr("OK"));
    connect(okButton, &QPushButton::clicked, this, &InputDialog::accept);

    QPushButton *cancelButton = new QPushButton(tr("Cancel"));
    connect(cancelButton, &QPushButton::clicked, this, &InputDialog::reject);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(lineEdit);
    layout->addWidget(okButton);
    layout->addWidget(cancelButton);

    setLayout(layout);
    setWindowTitle(tr("Input Dialog"));
}

QString InputDialog::getText() const {
    return lineEdit->text();
}
