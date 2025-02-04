#include "winnerdialog.h"
#include "ui_winnerdialog.h"

WinnerDialog::WinnerDialog(QString winnerName, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WinnerDialog)
{
    ui->setupUi(this);

    QPixmap background(":/winner_background.jpg");
    background =background.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, background);
    this->setPalette(palette);

    ui->winnerLabel->setText("Winner is " + winnerName + "!");

}

WinnerDialog::~WinnerDialog()
{
    delete ui;
}

void WinnerDialog::on_newgameButton_clicked()
{
    // Luodaan uusi peli.
    accept();
    emit newGame();
}

void WinnerDialog::on_exitButton_clicked()
{
    // Lopetataan peli kokonaan.
    emit exitFromWinnerDialog();
    reject();
}
