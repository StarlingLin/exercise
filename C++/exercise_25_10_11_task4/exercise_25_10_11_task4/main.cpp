#include <iostream>
#include <memory>

struct IDrawAPI
{
    virtual ~IDrawAPI() = default;
    virtual void drawRectangle(int x0, int y0, int x1, int y1) = 0;
    virtual void drawCircle(int cx, int cy, int r) = 0;
};

class ConsoleDraw : public IDrawAPI
{
public:
    void drawRectangle(int x0, int y0, int x1, int y1) override
    {
        std::cout << "Draw Rectangle: (" << x0 << "," << y0
            << ") to (" << x1 << "," << y1 << ")\n";
    }

    void drawCircle(int cx, int cy, int r) override
    {
        std::cout << "Draw Circle: (" << cx << "," << cy << ") R=" << r << "\n";
    }
};

class GUIDraw : public IDrawAPI
{
public:
    void drawRectangle(int x0, int y0, int x1, int y1) override
    {
        std::cout << "[GUI] Rectangle(" << x0 << "," << y0
            << ")-(" << x1 << "," << y1 << ")\n";
    }

    void drawCircle(int cx, int cy, int r) override
    {
        std::cout << "[GUI] Circle(" << cx << "," << cy << "), R=" << r << "\n";
    }
};

struct ITransformAPI
{
    virtual ~ITransformAPI() = default;
    virtual void translateRectangle(int& x0, int& y0, int& x1, int& y1, int dx, int dy) = 0;
    virtual void translateCircle(int& cx, int& cy, int& r, int dx, int dy) = 0;
};

class SimpleTranslate : public ITransformAPI
{
public:
    void translateRectangle(int& x0, int& y0, int& x1, int& y1, int dx, int dy) override
    {
        x0 += dx; y0 += dy; x1 += dx; y1 += dy;
    }

    void translateCircle(int& cx, int& cy, int& r, int dx, int dy) override
    {
        (void)r;
        cx += dx; cy += dy;
    }
};

class RectBiasTranslate : public ITransformAPI
{
public:
    void translateRectangle(int& x0, int& y0, int& x1, int& y1, int dx, int dy) override
    {
        x0 += dx; y0 += dy; x1 += dx; y1 += dy;
        ++x1; ++y1; 
    }

    void translateCircle(int& cx, int& cy, int& r, int dx, int dy) override
    {
        (void)r;
        cx += dx; cy += dy; 
    }
};

class Shape
{
public:
    virtual ~Shape() = default;
    virtual void draw() const = 0;
    virtual void transform(int offsetX, int offsetY) = 0;

    void setDrawAPI(std::shared_ptr<IDrawAPI> d) { mDraw = std::move(d); }
    void setTransformAPI(std::shared_ptr<ITransformAPI> t) { mTrans = std::move(t); }

protected:
    Shape(std::shared_ptr<IDrawAPI> d, std::shared_ptr<ITransformAPI> t)
        : mDraw(std::move(d)), mTrans(std::move(t))
    {
    }

    std::shared_ptr<IDrawAPI>     mDraw;
    std::shared_ptr<ITransformAPI> mTrans;
};

class Rectangle : public Shape
{
public:
    Rectangle(int x0, int y0, int x1, int y1,
        std::shared_ptr<IDrawAPI> d,
        std::shared_ptr<ITransformAPI> t)
        : Shape(std::move(d), std::move(t)), mX0(x0), mY0(y0), mX1(x1), mY1(y1)
    {
    }

    void draw() const override
    {
        mDraw->drawRectangle(mX0, mY0, mX1, mY1);
    }

    void transform(int offsetX, int offsetY) override
    {
        mTrans->translateRectangle(mX0, mY0, mX1, mY1, offsetX, offsetY);
    }

private:
    int mX0, mY0, mX1, mY1;
};

class Circle : public Shape
{
public:
    Circle(int cx, int cy, int r,
        std::shared_ptr<IDrawAPI> d,
        std::shared_ptr<ITransformAPI> t)
        : Shape(std::move(d), std::move(t)), mCenterX(cx), mCenterY(cy), mRadius(r)
    {
    }

    void draw() const override
    {
        mDraw->drawCircle(mCenterX, mCenterY, mRadius);
    }

    void transform(int offsetX, int offsetY) override
    {
        mTrans->translateCircle(mCenterX, mCenterY, mRadius, offsetX, offsetY);
    }

private:
    int mCenterX, mCenterY, mRadius;
};

int main()
{
    using std::make_shared;

    auto draw = make_shared<ConsoleDraw>(); 
    auto trans = make_shared<SimpleTranslate>(); 

    std::shared_ptr<Shape> rect = std::make_shared<Rectangle>(1, 2, 8, 10, draw, trans);
    std::shared_ptr<Shape> cir = std::make_shared<Circle>(2, 3, 5, draw, trans);

    rect->draw();
    cir->draw();

    rect->transform(3, 4);
    cir->transform(3, 4);

    rect->draw();
    cir->draw();

    rect->setTransformAPI(std::make_shared<RectBiasTranslate>());
    rect->transform(1, 1);
    rect->draw();

    rect->setDrawAPI(std::make_shared<GUIDraw>());
    cir->setDrawAPI(std::make_shared<GUIDraw>());
    rect->draw();
    cir->draw();

    return 0;
}
