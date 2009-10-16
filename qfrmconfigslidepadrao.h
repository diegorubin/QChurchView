#ifndef QFRMCONFIGSLIDEPADRAO_H
#define QFRMCONFIGSLIDEPADRAO_H

#include <QtGui/QDialog>
#include <QtGui/QPixmap>
#include <QtGui/QFileDialog>
#include <QtCore/QDir>
#include "ui_qfrmconfigslidepadrao.h"

class QfrmConfigSlidePadrao : public QDialog
{
    Q_OBJECT

public:
    QfrmConfigSlidePadrao(QWidget *parent = 0);
    ~QfrmConfigSlidePadrao();

    Ui::QfrmConfigSlidePadraoClass ui;

    void abrirImagem(QString filename);
    QString getImgFilename(){return imgFilename;}

private:
	QString imgFilename;
	QPixmap imgFundo;

private slots:
	virtual void selecionarImagem();


};

#endif // QFRMCONFIGSLIDEPADRAO_H
