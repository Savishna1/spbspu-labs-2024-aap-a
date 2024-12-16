#include "shape.hpp"

namespace averenkov
{
  double getLine(point_t a, point_t b)
  {
    return std::sqrt(std::pow(b.x - a.x, 2) + std::pow(b.y - a.y, 2));
  }
  void shapeScale(Shape* shap, point_t scale_center, double factor)
  {
    point_t pos = shap->getFrameRect().pos;
    double xplus = scale_center.x - pos.x;
    double yplus = scale_center.y - pos.y;
    xplus *= factor;
    yplus *= factor;
    point_t newpos;
    if (scale_center.x >= pos.x)
    {
      newpos.x = scale_center.x + xplus;
    }
    else
    {
      newpos.x = scale_center.x - xplus;
    }
    if (scale_center.y >= pos.y)
    {
      newpos.y = scale_center.y + yplus;
    }
    else
    {
      newpos.y = scale_center.y - yplus;
    }
    shap->move(newpos);
  }
}
