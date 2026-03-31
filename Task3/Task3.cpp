#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <glut.h>
#include <vector>
#include <cmath>

// Структура для удобного хранения координат вершин
struct Point {
    float x, y;
};

// Глобальные переменные для хранения списка отрисовки
GLuint sierpinskiList;
int iterations = 10; // Глубина рекурсии

// Функция для нахождения середины отрезка между двумя точками
Point midpoint(Point p1, Point p2) {
    return { (p1.x + p2.x) / 2.0f, (p1.y + p2.y) / 2.0f };
}

// Рекурсивная функция отрисовки узора Серпинского
void drawSierpinski(Point a, Point b, Point c, int depth) {
    if (depth == 0) {
        // Базовый случай: отрисовываем один заполненный треугольник
        glVertex2f(a.x, a.y);
        glVertex2f(b.x, b.y);
        glVertex2f(c.x, c.y);
    }
    else {
        // Шаг рекурсии: находим середины сторон
        Point ab = midpoint(a, b);
        Point bc = midpoint(b, c);
        Point ac = midpoint(a, c); // ИСПРАВЛЕНО: используем вершины a и c

        // Рекурсивно вызываем функцию для трех угловых треугольников
        drawSierpinski(a, ab, ac, depth - 1);
        drawSierpinski(ab, b, bc, depth - 1);
        drawSierpinski(ac, bc, c, depth - 1);
    }
}

// Создание списка отрисовки для фрактала (оптимизация)
void createSierpinskiList() {
    sierpinskiList = glGenLists(1);
    glNewList(sierpinskiList, GL_COMPILE);

    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.0f, 1.0f); // Синий цвет

    // Рассчитываем координаты для заполнения области от -5 до 5
    // Нижнее основание будет на уровне y = -4.5 (с небольшим отступом)
    // Верхняя точка на y = 4.5
    
    Point p1 = { 0.0f,  6.0f };          // Верхняя центральная точка
    Point p2 = { -5.5f, -4.0f};         // Левая нижняя
    Point p3 = { 5.5f, -4.0f};         // Правая нижняя

    drawSierpinski(p1, p2, p3, iterations);
    glEnd();

    glEndList();
}
void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0, 0, 5, 0, 1, 0, 0, 1, 0);

    // Отключаем освещение для фрактала, чтобы цвет был чистым
    glDisable(GL_LIGHTING);

    // Вызываем сохраненный список отрисовки
    glCallList(sierpinskiList);

    // Включаем освещение обратно, если планируется отрисовка других 3D объектов
    glEnable(GL_LIGHTING);

    glutSwapBuffers(); // Используем двойную буферизацию
}

void resize(int width, int height) {
    if (height == 0) height = 1;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    float aspect = (float)width / (float)height;

    // Сохраняем ортогональную проекцию (-5, 5), как в исходном коде
    if (width >= height) {
        glOrtho(-5.0 * aspect, 5.0 * aspect, -5.0, 5.0, 2.0, 12.0);
    }
    else {
        glOrtho(-5.0, 5.0, -5.0 / aspect, 5.0 / aspect, 2.0, 12.0);
    }
    glMatrixMode(GL_MODELVIEW);
}

void init(void) {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glClearColor(1.0, 1.0, 1.0, 1.0); // Белый фон

    // Генерируем фрактал один раз при инициализации
    createSierpinskiList();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    // Важно: GLUT_DOUBLE для плавности при 10 итерациях
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(50, 10);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Sierpinski Gasket - 10 Iterations");

    init();
    glutDisplayFunc(display);
    glutReshapeFunc(resize);
    glutMainLoop();
    return 0;
}