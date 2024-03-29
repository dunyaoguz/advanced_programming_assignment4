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

Canvas::Canvas(size_t rows, size_t columns, char fillChar)
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

int Canvas::getRows() const { return grid.size(); }

int Canvas::getColumns() const { return grid[0].size(); }

Canvas Canvas::flip_horizontal() const
{   
    Canvas hFlipped{grid.size(), grid[0].size()};
    size_t row_count = 0;
    for(std::vector<char> row : grid)
    {
        size_t col_count = row.size() - 1;
        for(size_t i = 0; i < row.size(); i++)
        {
            hFlipped.put(row_count, col_count, row[i]);
            col_count--;
        }
        row_count++;
    }
    return hFlipped;
}

Canvas Canvas::flip_vertical() const
{
    Canvas vFlipped{grid.size(), grid[0].size()};
    size_t row_count = grid.size() - 1;
    for(std::vector<char> row : grid)
    {
        for(size_t i = 0; i < row.size(); i++)
        {
            vFlipped.put(row_count, i, row[i]);
        }
        row_count--;
    }
    return vFlipped;
}

char Canvas::get(int r, int c) const { return grid.at(r).at(c); }

void Canvas::put(int r, int c, char ch)
{
    if(check(r, c)) 
    { 
        grid.at(r).at(c) = ch; 
    }
}

void Canvas::drawString(int r, int c, const std::string text)
{
    for (size_t i = 0; i < text.length(); i++, c++) 
    { 
        grid[r][c] = text[i]; 
    }
}

void Canvas::overlap(const Canvas& can, size_t r, size_t c)
{
    for (size_t row = 0; row < can.getRows(); row++)
    {
        for (size_t col = 0; col < can.getColumns(); col++)
        {
            if (can.get(row, col) != ' ') 
            {
                this->put(r + row, c + col, can.get(row, col));
            }
        }
    }
}

void Canvas::print(std::ostream& output) const
{
    for(std::vector row : grid) 
    {
        for (char col : row) 
        {
            output << col;
        }
        output << std::endl;
    }
}

std::ostream& operator<<(std::ostream& sout, const Canvas& can)
{
    can.print(sout);
    return sout;
}