#ifndef QFRMCONFIGDIRS_H
#define QFRMCONFIGDIRS_H

#include <QtGui/QDialog>
#include <QFileDialog>
#include "ui_qfrmconfigdirs.h"

class QfrmConfigDirs : public QDialog
{
    Q_OBJECT

public:
    QfrmConfigDirs(QWidget *parent = 0);
    ~QfrmConfigDirs();
    Ui::QfrmConfigDirsClass ui;

private:

	QFileDialog dlgArquivos;

private slots:
	virtual void AbrirDirSlides();
	virtual void AbrirDirTemas();
	virtual void AbrirDirLetras();
	virtual void AbrirDirPregadores();
	virtual void AbrirDirVideos();
	virtual void Cancelar();
};

#endif // QFRMCONFIGDIRS_H
