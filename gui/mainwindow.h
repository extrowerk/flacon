/* BEGIN_COMMON_COPYRIGHT_HEADER
 * (c)LGPL2+
 *
 * Flacon - audio File Encoder
 * https://github.com/flacon/flacon
 *
 * Copyright: 2012-2013
 *   Alexander Sokoloff <sokoloff.a@gmail.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.

 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * END_COMMON_COPYRIGHT_HEADER */


#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include <QPointer>

namespace Ui {
class MainWindow;
}

class Project;
class Converter;
class Scanner;

class MainWindow : public QMainWindow, private Ui::MainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void addFileOrDir(const QString &fileName);

public slots:
    void startConvert();
    void stopConvert();


private slots:
    void insertOutPattern(const QString &pattern);
    void replaceOutPattern(const QString &pattern);

    void setPattern();
    void deletePattern();
    void setOutDir();
    void setOutFormat();
    void setCodePage();

    void setControlsEnable();
    void refreshEdits();

    void openAddFileDialog();

    void openOutDirDialog();
    void setCueForDisc(Disk *disk);
    void setAudioForDisk(Disk *disk);
    void setCoverImage(Disk *disk);

    void removeDisks();

    void setStartTrackNum();
    void setTrackTag();


    void configure();
    void configureEncoder();

    void downloadInfo();
    void openScanDialog();

    void openAboutDialog();

protected:
    void closeEvent(QCloseEvent *) override;
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dropEvent(QDropEvent *event) override;
    void showEvent(QShowEvent * event) override;
    void keyPressEvent(QKeyEvent *event) override;
    bool event(QEvent *event) override;

private:
    QPointer<Converter> mConverter;
    Scanner *mScanner;
    QString getOpenFileFilter(bool includeAudio, bool includeCue);

    void initActions();
    void initOutFormatCombo();

    void loadSettings();
    void saveSettings();

    QIcon loadMainIcon();
};

#endif // MAINWINDOW_H
