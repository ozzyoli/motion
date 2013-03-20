#ifndef MANUALMOTIONTRACKER_H
#define MANUALMOTIONTRACKER_H

#include <QDialog>
#include <QPoint>
#include "video.h"
#include "selectpointimage.h"
#include "opencv2/core/core.hpp"

namespace Ui {
class ManualMotionTracker;
}

class ManualMotionTracker : public QDialog
{
    Q_OBJECT
    
public:
    explicit ManualMotionTracker(const Video* v, QWidget *parent = 0);
    ~ManualMotionTracker();
    
private:
    Ui::ManualMotionTracker *ui;
    const Video* v;
    int currentFrameNumber;
    int stepRate;
    Point2f* point;
    void setStepRate(int step);
    void previousFrame();
    void nextFrame();
    void setFrame(int frame);

    void registerPoint(const QPoint& point);
    void displayPoint();
    void clearPoint();

    void loadMarkings();
    void exportMarkings();

protected:
    void keyPressEvent(QKeyEvent* e);
private slots:
    void on_imageFrame_pointSelected(const QPoint &);
    void on_buttonBox_accepted();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_stepLineEdit_textChanged(const QString &arg1);
};

#endif // MANUALMOTIONTRACKER_H