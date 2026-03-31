#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <glut.h>

void resize(int width, int height)
{
    // Предотвращаем деление на ноль
    if (height == 0) height = 1;

    // Устанавливаем область просмотра на всё окно
    glViewport(0, 0, width, height);

    // Переходим в режим проектирования для настройки системы координат
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Вычисляем соотношение сторон окна
    float aspect = (float)width / (float)height;

    // Настраиваем ортогональную проекцию с сохранением пропорций
    // (используем те же границы -5..5, что и в вашем init)
    if (width >= height) {
        glOrtho(-5.0 * aspect, 5.0 * aspect, -5.0, 5.0, 2.0, 12.0);
    }
    else {
        glOrtho(-5.0, 5.0, -5.0 / aspect, 5.0 / aspect, 2.0, 12.0);
    }

    // Возвращаемся в режим моделирования
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 0, 5, 0, 1, 0, 0, 1, 0);
}

void displayFigures(void)
{
    glLineWidth(1);
    glBegin(GL_LINES);

    glColor3d(1, 0, 0);
    glVertex3d(0.5, -2, 0);
    glVertex3d(1.5, -1, 0);

    glColor3d(0, 1, 0);
    glVertex3d(1.5, -1, 0);
    glColor3d(0, 0, 1);
    glVertex3d(1.5, -3, 0);

    glColor3d(1, 0, 0);
    glVertex3d(1, -2.5, 0);
    glVertex3d(1.5, -3, 0);

    glColor3d(1, 0, 0);
    glVertex3d(1, -2.5, 0);
    glVertex3d(2, -2, 0);

    glColor3d(1, 0, 0);
    glVertex3d(2, -3, 0);
    glVertex3d(2, -2, 0);

    glEnd();

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // см. выше
    glBegin(GL_TRIANGLES);
    glColor3d(0, 0, 1);      // рисуем треугольник
    glVertex3d(3, -1.5, 0);
    glVertex3d(3.5, -1, 0);
    glVertex3d(3.8, -1.7, 0);
    glEnd();

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // см. выше
    glBegin(GL_QUADS);
    glColor3d(0, 0, 0);      // рисуем треугольник
    glVertex3d(2, -3.5, 0);
    glVertex3d(3, -4, 0);
    glVertex3d(4, -3, 0);
    glVertex3d(3, -3, 0);
    glEnd();

}
void displayQuads(void)
{
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // см. выше
    glBegin(GL_QUADS);

    glColor3d(0, 0, 1);      // рисуем треугольник
    glVertex3d(1.5, 1, 0);
    glVertex3d(1.5, 2, 0);
    glVertex3d(0.5, 2, 0);
    glVertex3d(0.5, 1, 0);

    glColor3d(1, 0, 0);      // рисуем треугольник
    glVertex3d(1.5, 2, 0);
    glVertex3d(1.5, 3, 0);
    glVertex3d(0.5, 3, 0);
    glVertex3d(0.5, 2, 0);

    glColor3d(1, 1, 0);      // рисуем треугольник
    glVertex3d(1.5, 3, 0);
    glVertex3d(1.5, 4, 0);
    glVertex3d(0.5, 4, 0);
    glVertex3d(0.5, 3, 0);

    glColor3d(0, 0, 0);      // рисуем треугольник
    glVertex3d(1.5, 4, 0);
    glVertex3d(1.5, 5, 0);
    glVertex3d(0.5, 5, 0);
    glVertex3d(0.5, 4, 0);

    glEnd();

}
void displayTriagles(void)
{
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // см. выше
    glBegin(GL_TRIANGLES);
    glColor3d(0, 0, 1);      // рисуем треугольник
    glVertex3d(3.3, 2.5, 0);
    glVertex3d(3.5, 2, 0);
    glVertex3d(2, 2, 0);

    glColor3d(0, 1, 0);      // рисуем треугольник
    glVertex3d(3.3, 1.5, 0);
    glVertex3d(3.5, 2, 0);
    glVertex3d(2, 2, 0);

    glColor3d(1, 0, 0);      // рисуем треугольник
    glVertex3d(3.3, 1.5, 0);
    glVertex3d(3, 1, 0);
    glVertex3d(2, 2, 0);

    glColor3d(0, 1, 1);      // рисуем треугольник
    glVertex3d(2.7, 0.7, 0);
    glVertex3d(3, 1, 0);
    glVertex3d(2, 2, 0);

    glColor3d(1, 0, 1);      // рисуем треугольник
    glVertex3d(3.3, 2.5, 0);
    glVertex3d(3, 3, 0);
    glVertex3d(2, 2, 0);

    glColor3d(1, 1, 1);      // рисуем треугольник
    glVertex3d(2.7, 3.3, 0);
    glVertex3d(3, 3, 0);
    glVertex3d(2, 2, 0);

    glEnd();

}
void displayPoints(void)
{
    glPointSize(15);
    glEnable(GL_POINT_SMOOTH);
    glBegin(GL_POINTS);
    glColor3d(0, 0, 1);
    glVertex3d(-4, -3, 0); // первая точка

    glColor3d(1, 1, 0);
    glVertex3d(-4, -2, 0);   // вторая точка

    glEnd();
    glDisable(GL_POINT_SMOOTH);

    glPointSize(10);
    glBegin(GL_POINTS);

    glColor3d(0, 1, 0);
    glVertex3d(-2, -3, 0);   // вторая точка

    glColor3d(1, 0, 0);     // четвертая
    glVertex3d(-2, -2, 0);

    glEnd();
}
void displayLines(void)
{
    glLineWidth(2);       // ширину линии 
    // устанавливаем 1
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_LINE_STIPPLE); // разрешаем рисовать 
    glLineStipple(1, 1);    // устанавливаем маску
    glBegin(GL_LINES);

    glColor3d(1, 0, 0);
    glVertex3d(-4, 5, 0);
    glVertex3d(-3, 3, 0);

    glEnd();
    glDisable(GL_LINE_SMOOTH);
    glDisable(GL_LINE_STIPPLE);

    glLineWidth(1);       // ширину линии 
    glBegin(GL_LINES);
    glColor3d(1, 1, 0);     // желтый цвет
    glVertex3d(-4, 4, 0); // первая линия
    glVertex3d(-3, 5, 0);

    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);

    glColor3d(0, 1, 0);     // зеленый
    glVertex3d(-4, 3, 0); // первая линия
    glVertex3d(-3, 4, 0);

    glEnd();
}
void displayPops(void)
{

    glLineWidth(1);       // ширину линии 
    // устанавливаем 1
    glBegin(GL_LINES);

    glColor3d(0, 0, 0);     // красный цвет
    glVertex3d(0, 8, 0); // первая линия
    glVertex3d(0, -8, 0);

    glColor3d(0, 0, 0);     // зеленый
    glVertex3d(-8, 0, 0); // вторая линия
    glVertex3d(8, 0, 0);

    glEnd();
}
void drawBitmapText(float x, float y, const char* text)
{
    // Устанавливаем позицию растра
    glRasterPos3f(x, y, 0);
    for (const char* c = text; *c != '\0'; ++c)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
}

void displayLabels()
{
    // Отключаем освещение, чтобы текст был чистого цвета, а не серым
    glDisable(GL_LIGHTING);
    glColor3d(0, 0, 0); // Черный цвет для текста

    // Текст AP-426 (идентификатор группы)
    drawBitmapText(-1.0f, 1.0f, "AP-426");

    // Метки для точек
    drawBitmapText(-1.8f, -3.2f, "Green");
    drawBitmapText(-1.8f, -2.2f, "Red");
    drawBitmapText(-4.2f, -3.2f, "Blue");
    drawBitmapText(-4.2f, -2.2f, "Yellow");

    glEnable(GL_LIGHTING);
}   

void display(void)
{
    // Очищаем буферы цвета и глубины перед каждым кадром
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    // Устанавливаем камеру (повторяем параметры из gluLookAt)
    gluLookAt(0, 0, 5, 0, 1, 0, 0, 1, 0);

    displayPoints();
    displayLines();
    displayPops();
    displayTriagles();
    displayQuads();
    displayFigures();
    displayLabels(); // Отрисовка текста поверх всего

    glFlush();
}
void init(void)
{
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    glClearColor(1, 1, 1, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-5.0, 5.0, -5.0, 5.0, 2.0, 12.0);
    glMatrixMode(GL_MODELVIEW);
    gluLookAt(0, 0, 5, 0, 1, 0, 0, 1, 0);

}
int main(int argc, char** argv)
{
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(50, 10);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Hello");
    glutReshapeFunc(resize);
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(resize);
    glutMainLoop();
    return 0;
}