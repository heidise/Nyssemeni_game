#ifndef WINNERDIALOG_H
#define WINNERDIALOG_H

#include <QDialog>
#include <QString>

/**
 * @brief The WinnerDialog class Pelin loppudialogi. Peli on loppunut ja pelin voittaja näytetään.
 * Käyttäjä voi halutessaan aloittaa loppudialogissa uuden pelin.
 */

namespace Ui {
class WinnerDialog;
}

class WinnerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit WinnerDialog(QString winnerName, QWidget *parent = nullptr);
    ~WinnerDialog();

signals:
    void exitFromWinnerDialog();
    void newGame();

private slots:
    void on_newgameButton_clicked();

    void on_exitButton_clicked();

private:
    Ui::WinnerDialog *ui;
};

#endif // WINNERDIALOG_H
