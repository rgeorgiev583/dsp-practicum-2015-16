#include<iostream>
#include<vector>
using namespace std;

struct Edge { //ползва се за представянето на граф, чрез списък на ребрата
	int a, b;
};

class Graph {
private:
	vector<int> beginning; //списък, указващ от къде до къде са съседите на елемент в neighbors
	vector<int> neighbors; //списък на съседи на даден елемент
public:
	vector<int> getBeginning() { return beginning; }
	vector<int> getNeighbors() { return neighbors; }

	void setBeginning(vector<int> newBeg) {
		beginning.clear();
		for (int i = 0; i < newBeg.size(); i++)
		{
			beginning.push_back(newBeg[i]);
		}
	}

	void setNeighbors(vector<int> newNei) {
		neighbors.clear();
		for (int i = 0; i < newNei.size(); i++)
		{
			neighbors.push_back(newNei[i]);
		}
	}

	void print()
	{
		cout << "Beginning vector:" << endl;
		for (int i = 1; i <= beginning.size(); i++)
		{
			cout << i << " - " << beginning[i - 1] << endl;
		}
		cout << endl << "Neighbors vector:" << endl;
		for (int i = 1; i <= neighbors.size(); i++)
		{
			cout << neighbors[i - 1] << " - " << i << endl;
		}
	}

	bool areIncidental(int a, int b)//връща дали са съседи 2 върха
	{
		if (a<1 || b<1 || a>beginning.size() || b>beginning.size())
		{//проверка дали съществува връх
			cout << "Vertex doesn't exist. Returning false." << a << " " << b << endl;
			return false;
		}
		if (a == b)
			return false;

		if (a == beginning.size())
		{
			for (int i = beginning[a - 1]; i < neighbors.size(); i++)
			{
				if (b == neighbors[i])
					return true;
			}
		}
		else {
			for (int i = beginning[a - 1]; i < beginning[a]; i++)
			{
				if (b == neighbors[i])
					return true;
			}
		}

		if (b == beginning.size())
		{
			for (int i = beginning[b - 1]; i < neighbors.size(); i++)
			{
				if (a == neighbors[i])
					return true;
			}
		}
		else {
			for (int i = beginning[b - 1]; i < beginning[b]; i++)
			{
				if (a == neighbors[i])
					return true;
			}
		}
		return false;
	}

	bool isValidRoad(vector<int> road)
	{
		for (int i = 0; i < road.size() - 1; i++)
		{
			if (!areIncidental(road[i], road[i + 1]))
				return false;
		}
		return true;
	}

	bool** getIncidentalMatrix()
	{
		bool **incidentalMatrix = 0;
		incidentalMatrix = new bool*[beginning.size()];
		for (int i = 1; i <= beginning.size(); i++)
		{
			incidentalMatrix[i - 1] = new bool[beginning.size()];
			for (int j = 1; j <= beginning.size(); j++)
			{
				incidentalMatrix[i - 1][j - 1] = areIncidental(i, j);
			}
		}
		return incidentalMatrix;
	}

	void makeEdgeList(vector<Edge>& vect)
	{
		Edge temp;
		vect.clear();
		for (int i = 1; i <= beginning.size(); i++)
		{
			for (int j = 1; j < i; j++)
			{
				if (areIncidental(i, j))
				{
					temp.a = i;
					temp.b = j;
					vect.push_back(temp);
				}
			}
		}
	}
};

int main()
{
	//http://tu-utc.com/Webpages/E_learning/SAA/Tema5-TREE1_files/image021.gif
	//линк към картинка на графът, който съм ползвал за пример
	Graph example;
	vector<int> beg;
	beg.push_back(1);
	beg.push_back(3);
	beg.push_back(7);
	beg.push_back(11);
	beg.push_back(14);
	vector<int> nei;
	nei.push_back(2);
	nei.push_back(3);
	nei.push_back(1);
	nei.push_back(2);
	nei.push_back(4);
	nei.push_back(5);
	nei.push_back(1);
	nei.push_back(2);
	nei.push_back(4);
	nei.push_back(5);
	nei.push_back(2);
	nei.push_back(3);
	nei.push_back(5);
	nei.push_back(2);
	nei.push_back(3);
	nei.push_back(4);
	example.setBeginning(beg);//слагаме начало и съседи на примерния граф
	example.setNeighbors(nei);
	example.print();

	vector<int> road;//примерен тест за път в графа
	road.push_back(1);
	road.push_back(2);
	road.push_back(4);
	road.push_back(3);
	road.push_back(1);
	cout << endl << "Road is " << example.isValidRoad(road) << endl;

	bool **incM = new bool*;//графът, представен като матрица на съседство
	incM = example.getIncidentalMatrix();
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << incM[i][j] << " ";
		}
		cout << endl;
	}
	
	cout << endl;
	vector<Edge> edgeList;//графът, представен като списък на ребра
	example.makeEdgeList(edgeList);
	for (int i = 0; i < edgeList.size(); i++)
	{
		cout << "A=" << edgeList[i].a << " " << "B=" << edgeList[i].b << endl;
	}


	system("pause");
	return 0;
}
