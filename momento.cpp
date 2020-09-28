#include <iostream>
#include <string>
#include <list>
using namespace std;

/*Momento pattern used for implementing undo mechanism*/

class EditorState
{
private:
	string content;
public:
	EditorState(string content)
	{
		this->content = content;
	}
	string getContent()
	{
		return content;
	}
};

class Editor
{
private:
	string content;
public:

	string getContent()
	{
		return content;
	}
	void setContent(string content)
	{
		this->content = content;
	}
	EditorState createState()
	{
		return EditorState(content);
	}
	void restore(EditorState state)
	{
		content = state.getContent();
	}
};

class History
{
private:
	list<EditorState> states;
public:
	void push(EditorState state)
	{
		states.push_back(state);
	}
	EditorState pop()
	{
		EditorState lastState = states.back();
		states.pop_back();
		return lastState;
	}

};

int main()
{
	Editor editor;
	History history;
	editor.setContent("a");
	history.push(editor.createState());

	editor.setContent("b");
	history.push(editor.createState());

	editor.setContent("c");
	editor.restore(history.pop());	//returns b
	editor.restore(history.pop());	//returns a

	cout << editor.getContent() << endl;
}