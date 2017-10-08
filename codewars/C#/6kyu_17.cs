using System;
public class Point
{
    public double X;
    public double Y;
    public double Z;

    public Point(double x, double y, double z)
    {
        X = x;
        Y = y;
        Z = z;
    }

    public static Point GetOrigin()
    {
        return new Point(0.0, 0.0, 0.0);
    }

    public double GetDistanceFromOrigin()
    {
        return Math.Sqrt(X * X + Y * Y + Z * Z);
    }

    public double GetDistanceFromPoint(Point p)
    {
        return Math.Sqrt((p.X - X) * (p.X - X) + (p.Y - Y) * (p.Y - Y) + (p.Z - Z) * (p.Z - Z));
    }
}