#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    // Määritetään minimi- ja maksimipelaajamäärä.
    ui->players->setRange(1,4);

    // Määritetään pelaajien oletusnimet. Käyttäjä voi muuttaa näitä aloitusdialogissa.
    ui->player1Name->setText("Player1");
    ui->player2Name->setText("Player2");
    ui->player3Name->setText("Player3");
    ui->player4Name->setText("Player4");

    // Määritetään pelaajien nimien maksimipituus.
    ui->player1Name->setMaxLength(10);
    ui->player2Name->setMaxLength(10);
    ui->player3Name->setMaxLength(10);
    ui->player4Name->setMaxLength(10);

}
Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_startbutton_clicked()
{
    // Lähetetään käyttäjän määrittämät pelaajalukumäärä ja pelaajien nimet signaaleina.
    emit numberOfPlayers(players_);
    emit playerNames(player1_name_, player2_name_, player3_name_, player4_name_);
    accept();
}

void Dialog::on_exitbutton_clicked()
{
    // Lopetetaan peli. Lähetetään lopetussignaali.
    emit exitFromDialog();
    reject();
}


void Dialog::on_players_valueChanged(int arg1)
{
    // Pelaajien lukumäärä.
    players_ = arg1;
}

void Dialog::on_player1Name_textChanged(const QString &arg1)
{
    player1_name_ = arg1;
}

void Dialog::on_player2Name_textChanged(const QString &arg1)
{
    player2_name_ = arg1;
}

void Dialog::on_player3Name_textChanged(const QString &arg1)
{
    player3_name_ = arg1;
}

void Dialog::on_player4Name_textChanged(const QString &arg1)
{
    player4_name_ = arg1;
}
