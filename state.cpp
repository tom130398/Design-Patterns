#include <iostream>
using namespace std;

enum ToolType{SELECTION, BRUSH, ERASER};
/*State design pattern used when an object changes its behavior based on its internal state*/

//implement a interface using abstract class by declaring its functions as pure private funcitons
class Tool
{
public:
	virtual void mouseUp() = 0;		//add = 0 at the end of virtual function to make it a pure virtual funciton
	virtual void mouseDown() = 0;
};

class SelectionTool:public Tool
{
public:
	void mouseUp()
	{
		cout << "Selection icon" << endl;
	}
	void mouseDown()
	{
		cout << "Draw dashed rectangle" << endl;
	}
};

class BrushTool:public Tool
{
public:
	void mouseUp()
	{
		cout << "Brush icon" << endl;
	}
	void mouseDown()
	{
		cout << "Draw a line" << endl;
	}	
};

class Canvas
{
private:
	Tool *currentTool;
public:
	void mouseUp()
	{
		currentTool->mouseUp();
	}
	void mouseDown()
	{
		currentTool->mouseDown();
	}
	void setCurrentTool(Tool *currentTool)
	{
		this->currentTool = currentTool;
	}
};

int main()
{
	Canvas canvas;
	Tool *selection = new BrushTool;
	canvas.setCurrentTool(selection);
	canvas.mouseDown();
	canvas.mouseUp();
}