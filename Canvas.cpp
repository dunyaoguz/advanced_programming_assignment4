#include "Canvas.h"

bool Canvas::check(int r, int c) const
{
    try 
    { 
        std::vector<char> row = grid.at(r);
        try 
        { 
            row.at(c); 
            return true;
        }
        catch(const std::out_of_range& e) 
        { 
            return false; 
        }
    }
    catch(const std::out_of_range& e) 
    { 
        return false; 
    }
}

void Canvas::resize(size_t rows, size_t cols)
{
    for(std::vector<char> col : grid)
    {
        col.resize(cols);
    }
    grid.resize(rows);
}

Canvas::Canvas(int rows, int columns, char fillChar)
{
    for(size_t i = 0; i<rows; i++)
    {
        std::vector<char> row;
        for(size_t i = 0; i<columns; i++)
        {
            row.push_back(fillChar);
        }
        grid.push_back(row);
    }
}

int Canvas::getRows() const
{
    return grid.size();
}

int Canvas::getColumns() const
{
    return grid[0].size();
}

Canvas Canvas::flip_horizontal() const
{   
    Canvas hFlipped{grid.size(), grid[0].size()};
    for(std::vector<char> col : grid)
    {
        size_t row_count = 0;
        size_t col_count = col.size() - 1;
        for(size_t i = 0; i < col.size(); i++)
        {
            hFlipped.put(row_count, col_count, col[col_count]);
            col_count--;
        }
    }
    return hFlipped;
}

Canvas Canvas::flip_vertical() const
{
    Canvas vFlipped{grid.size(), grid[0].size()};
    for(std::vector<char> col : grid)
    {
        size_t row_count = grid.size() - 1;
        size_t col_count = 0;
        for(size_t i = 0; i < col.size(); i++)
        {
            vFlipped.put(row_count, col_count, col[col_count]);
            col_count--;
        }
    }
    return vFlipped;
}

char Canvas::get(int r, int c) const
{
    return grid.at(r).at(c);
}

void Canvas::put(int r, int c, char ch)
{
    if(check(r, c)) { grid.at(r).at(c) = ch; }
}

void Canvas::drawString(int r, int c, const std::string text)
{

}

void Canvas::overlap(const Canvas& can, size_t r, size_t c)
{

}

void Canvas::print(std::ostream&) const
{

}

std::ostream& operator<<(std::ostream& sout, const Canvas& can)
{

}