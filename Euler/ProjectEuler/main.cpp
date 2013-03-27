//#include <QApplication>
//#include "qmlapplicationviewer.h"
#include "funcs.h"

//Q_DECL_EXPORT
int main()/*int argc, char *argv[]*/
{
    /*QScopedPointer<QApplication> app(createApplication(argc, argv));

    QmlApplicationViewer viewer;
    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
    viewer.setMainQmlFile(QLatin1String("qml/ProjectEuler/main.qml"));
    viewer.showExpanded();*/

    printf("Problem 1. Answer: %f\n", pje1());
    printf("Problem 2. Answer: %f\n", pje2());
    printf("Problem 3. Answer: %f\n", pje3());
    printf("Problem 4. Answer: %f\n", pje4());
    printf("Problem 5. Answer: %d\n", pje5());
    printf("Problem 6. Answer: %f\n", pje6());
    printf("Problem 7. Answer: %f\n", pje7());
  //  pje8();
    cout << "Problem 9. Product of abc=" << pje9() << endl;
    cout.precision(15);
    cout << "Problem 10. Answer: " << pje10() <<endl;
    cout << "Problem 11. Answer: " << pje11() <<endl;
    return(0);
    //return app->exec();
}
