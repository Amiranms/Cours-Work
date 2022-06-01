#include "City.h"
const int N = 8;
const int inf = 1000000000;
template <int N>//шаблонный класс Авиакомпания,количество городов и соотвественно размер матрицы
class Aviacompany {//определеяется для каждого экземлпяра класса индивидуально
private:
	City a_list[N];
	Inf_segment a_table[N][N];

	//alghoritm dijcstra
	vector<int> shortcut(int s, int f, char how)//string from, string where)//, char how)
	{
		//int s =..;//search_for_number(from);
		//int f =..;//search_for_number(where);

		int qiuantity_nodes = 0;

		vector<double> dist(N, inf);//инициализируем вектор,который будет содержать 
		//информация о расстоянии от s до всех остальных городов 
		dist[s] = 0;//вершина из которой нас интересут расстояние до F -
		//-находится на расстоянии 0 от себя самой

		vector<int> p(N);//просто вектор,в котором на i-ом месте стоиt номер вершины из которой мы пришли в нее
		p[s] = -1;//потому что в начальную мы не пришли ниоткуда 

		vector<bool> util(N, false);//инициализируем вектор,который будет сообщать
		//посещали мы вершину(город) или нет
		//это переменная,для того чтобы выбрать в каком соотношении нам нужно выбрать time/money для сбалансированного поиска
		int position = 0;
		if (how == '&') {
			cout << endl << "Time [ | | | | | | | | | ] Money " << endl << "Select a position from 1 to 9" << endl << ">";
			cin >> position;
			while (position < 1 || position>9) {
				cout << "Incorrect value.Try again!" << endl << ">";
				cin >> position;
			}
		}

		//проходимся по всем вершинам
		for (int i = 0; i < N; i++) {//в худшем случае нам может потребоваться N итераций
			int v = -1;

			//в данном for цикле мы ищем город с минимальным расстоянием
			//в который мы еще не зашли 
			for (int j = 0; j < N; j++)
				if (!util[j] && (v == -1 || dist[j] < dist[v]))
					v = j;

			//на случай,если мы уже рассмотрели все доступные вершины 
			//и остались только недостижимые
			if (dist[v] == inf)
				break;

			util[v] = true;//пометили как посещенную

				//основной цикл
			for (int j = 0; j < N; j++) {//все вершины инцидентные нашей v
				if (a_table[v][j].iGetE() == '1')//если полет существует 
				{
					qiuantity_nodes++;
					int to = j;//вершина в кот летим
					int time_p = 0;
					double money_p = 0;
					double mt = 0;

					switch (how) {

					case '%':
						time_p = ((a_table[v][j]).iGetH()) * 60 + (a_table[v][j]).iGetM();//время которое нам требует из v в t0

						if (dist[v] + time_p < dist[to])
						{//если расстояние(время и тд...) от s(start) до to больше чем расстояние(..) от s(start) до v + distance(v-t)
							dist[to] = dist[v] + time_p;//то мы меняем расстояние до to на более короткое
							p[to] = v;//а в массиве в котором каждой i-ой присваевается j-ая из которой пришли мы укзаываем,что в to пришли из v
						}

						break;

					case '$':

						money_p = a_table[v][j].iGetC();//деньги которые нам потребуются из v в t0

						if (dist[v] + money_p < dist[to])
						{//если расстояние(время и тд...) от s(start) до to больше чем расстояние(..) от s(start) до v + distance(v-t)
							dist[to] = dist[v] + money_p;//то мы меняем расстояние до to на более короткое
							p[to] = v;//а в массиве в котором каждой i-ой присваевается j-ая из которой пришли мы укзаываем,что в to пришли из v
						}
						break;
					case '&':

						mt = (static_cast<double>(a_table[v][j].iGetT() *(position/10)))+ (((a_table[v][j]).iGetM()) * (10-position)/10) ;
						if (dist[v] + mt < dist[to])
						{//если расстояние(время и тд...) от s(start) до to больше чем расстояние(..) от s(start) до v + distance(v-t)
							dist[to] = dist[v] + mt;//то мы меняем расстояние до to на более короткое
							p[to] = v;//а в массиве в котором каждой i-ой присваевается j-ая из которой пришли мы укзаываем,что в to пришли из v
						}
						break;

					default:
						cout << endl << "EROR function \"shortcut\" : invalid search atribute" << endl;
						vector<int> null_vec(0);
						return null_vec;

					}//switch


				}
			}
		}


		switch (how) {
		case '$':
			cout << endl << "The lowest cost of flight is " << dist[f] << " RUB";
			break;
		case '%':
			cout << endl << "Shortest time is " << static_cast<int>(dist[f]) / 60 << " hours " << static_cast<int>(dist[f]) % 60 << " minutes";
			break;
		default:
			cout << endl << "Balanced in terms of cost and flight time";
			break;
		}


		vector<int> path;//конструируем путь до нашей вершины в обрятном порядке
		for (int v = f; v != s; v = p[v])
			path.push_back(v);
		path.push_back(s);
		reverse(path.begin(), path.end());//меняем местами наш векторный массив

		path.push_back(qiuantity_nodes);
		return path;

	}//function end


	//вспомогательные функции
	void printPath(vector<int> path)//получаем на вход вектор из номеров городов,а печатаем путь с названиями городов
	{
		for (int i = 0; i < path.size(); i++)
		{
			if (i != (path.size() - 1))
			{
				cout << a_list[path[i]].cGetN() << "--->";
				continue;
			}
			cout << a_list[path[i]].cGetN();
		}
		cout << endl << endl;

	}
	double getPathCost(vector<int> path)//количество денег,которое потребуется на данный путь
	{
		int sum = 0;
		for (int i = 0; i < ((int)path.size() - 1); i++)
		{
			sum += a_table[path[i]][path[i + 1]].iGetC();

		}
		return sum;
	}
	int getPathTime(vector<int> path)//количество минут,которое потребуется на данный путь
	{
		int minutes = 0;
		for (int i = 0; i < ((int)path.size() - 1); i++)
		{
			minutes += a_table[path[i]][path[i + 1]].iGetT();

		}
		return (minutes);
	}
	double getPathBalance(vector<int> path, int position) {
		double bal = 0;
		for (int i = 0; i < path.size()-1; i++) {
			bal += a_table[path[i]][path[i + 1]].iGetT() * position / 10 + a_table[path[i]][path[i + 1]].iGetC() * (10 - position) / 10;
		}
		return bal;
	}
	bool is_used(vector<int> path, int node)//функция,которая будет определяться проходили ли мы черещ эту вершину,т.к наши пути не содержат циклов,то было 
	{//бы логично предположить,что дважды через одну вершину мы не проходим 
		vector<int>::iterator it = path.begin();
		for (; it != path.end(); it++) {
			if (*it == node)
				return true;
		}
		return false;
	}

	//рукурсивный вывод всех путей из А в Б
	void foo(int init_node, int  fin_node, vector<int> path, char how,multimap<double,vector<int>> & mm,int position,int prev = -1)
	{//по сути эта функция заполняет наш словарь " мультимап" в зависимости от того по какому признаку мы хотим сортировать
	//ключ (либо стоимость,либо время,либо баланс) --- путь состоящий из номеров городов,в которые мы залетаем 
	//position - переменная на случай если cортируем сбалансированно по времени и деньгам инит нод - вершина у которой мы смотрим соседей 
	//фин нод - искомая вершина 
		path.push_back(init_node); // добавляем в путь текущую ноду


		if (init_node == fin_node)
		{
			add_to_map(mm, path, how,position);
			path.pop_back();
			return;
		}
		//**проверка,не зашли ли мы в тупик,проверяем есть ли у вершины на которой мы сейчас находимся инцидентные помимо той,из которой мы пришли
		int flag = 0;
		for (int i = 0; i < N; i++)
		{
			if (a_table[init_node][i].iGetE() == '1')
				flag++;
		}
		if (flag == 1){

			return;
		}

		//рекурсивно продолжаем поиск для дочерних нод 

		for (int i = 0; i < N; i++)
		{
			if ((a_table[init_node][i].iGetE() == '1') && !(is_used(path, i)))
				foo(i, fin_node, path, how,mm,position, init_node);
		}

	}


	//реализация алгоритма флойда
	//алгоритмическая сложность n^3
	vector<int> FloydAlghorith(int from, int where, char how)
	{
		int qiuantity_nodes = 0;//количество обращенных вершин
		Inf_segment curTable[N][N];//вспомогательная матрица с инф сегментами,т.к мы будем менять ее в процессе
		for (int i = 0; i < N; i++)//поиска кратчайшего пути,то нам приоритетнее не портить основную матрицу авиакомпании
		{
			for (int j = 0; j < N; j++)
			{
				curTable[i][j] = a_table[i][j];
			}
		}

		int ArrPath[N][N];//матрица,которая позволит нам найти именно сам путь(а-б-в-париж..)
		for (int i = 0; i < N; i++)//инициализируем по принципу(i = j -> a[i][j] = 0,else a[i][j] =-1)
			for (int j = 0; j < N; j++) {
				if (i == j)
					ArrPath[i][j] = 0;
				else
					ArrPath[i][j] = -1;
			}

		vector<int> path;
		int position = 0;//это переменная,для того чтобы выбрать в каком соотношении нам нужно выбрать time/money для сбалансированного поиска
		if (how == '&') {
			cout << endl << "Time [ | | | | | | | | | ] Money " << endl << "Select a position from 1 to 9" << endl << ">";
			cin >> position;
			while (position < 1 || position>9) {
				cout << "Incorrect value.Try again!" << endl << ">";
				cin >> position;
			}
		}
		for (int k = 0; k < N; k++)
		{
			for (int i = 0; i < N; i++)
			{
				for (int j = i + 1; j < N; j++)
				{
					if (curTable[k][j].iGetE() == '1' && curTable[i][k].iGetE() == '1') //если существует промежуточный путь между i and j
					{
						qiuantity_nodes++;
						if (curTable[i][j].iGetE() == '0')//если самого i<->j не существет
						{
							curTable[i][j] = curTable[i][k] + curTable[k][j];//то промежуточный - оптимальный
							curTable[j][i] = curTable[i][k] + curTable[k][j];
						}

						switch (how) {
						case '$'://поиск  наилучшего по стоимости
							if (curTable[i][j].iGetC() > curTable[i][k].iGetC() + curTable[k][j].iGetC()) //если промежуточный - еффективнее
							{
								curTable[i][j] = curTable[i][k] + curTable[k][j];
								curTable[j][i] = curTable[i][k] + curTable[k][j];
								ArrPath[i][j] = ArrPath[j][i] = k;
							}
							break;
						case '%'://пиоиск наилучшего по времени
							if (curTable[i][j].iGetT() > curTable[i][k].iGetT() + curTable[k][j].iGetT()) //если промежуточный - еффективнее
							{
								curTable[i][j] = curTable[i][k] + curTable[k][j];
								curTable[j][i] = curTable[i][k] + curTable[k][j];
								ArrPath[i][j] = ArrPath[j][i] = k;
							}
							break;
						case '&'://сбалансированный 
							if ((curTable[i][j].iGetT() * position / 10 )+ (curTable[i][j].iGetC()*(10-position)/10) > (curTable[i][k].iGetT()* position / 10 )+ (curTable[i][k].iGetC()* (10 - position) / 10)
								+ (curTable[k][j].iGetT() * position / 10) + (curTable[k][j].iGetC() * (10 - position) / 10)) //если промежуточный - еффективнее
							{
								curTable[i][j] = curTable[i][k] + curTable[k][j];
								curTable[j][i] = curTable[i][k] + curTable[k][j];
								ArrPath[i][j] = ArrPath[j][i] = k;
							}
							break;

						}
					}//if end

				}//third for

			}//second for

		}//first for

		cout << endl;

		switch (how) {
		case '$':
			cout << endl << "The lowest cost of flight is " << curTable[from][where].iGetC() << " RUB";
			break;
		case '%':
			cout << endl << "Shortest time is " << curTable[from][where].iGetH() << " hours " << curTable[from][where].iGetM() << " minutes";
			break;
		default:
			cout << endl << "Balanced in terms of cost and flight time";
			break;
		}

		//выводим наш путь в вектор,где будут циферки короче
		path.push_back(where);
		while (ArrPath[from][where] != -1) {
			path.push_back(ArrPath[from][where]);
			where = ArrPath[from][where];
		}
		path.push_back(from);
		reverse(path.begin(), path.end());
		path.push_back(qiuantity_nodes);

		return path;
	}



public:
	Aviacompany()
	{
		cout << endl << "Aviacompany constructor worked" << endl;
	}

	string aGetN(int i) { return a_list[i-1].cGetN(); }//получение имени города по его номеру

	void Filling_table()///программа для заполнения нашей матрицы
	{//смежности посредством ввода через консоль

		for (int i = 0; i < N; i++)
		{
			cout << endl << "Enter the city name" << endl;
			string str;
			getline(cin, str);

			a_list[i].cSetN(str);

		}

		int temp_int;
		double temp_double;
		char temp_char;

		for (int i = 0; i < N; i++)
			for (int j = i; j < N; j++) {

				if (i == j) {
					a_table[i][j].iSetE('0');
					continue;
				}

				cout << endl << "for the flight:\n" << "FROM " << a_list[i].cGetN() << " TO " << a_list[j].cGetN() << endl;
				cout << "Is it exists,Capitain????" << endl;
				cin >> temp_char;
				if (temp_char == '1') {

					a_table[i][j].iSetE('1');
					a_table[j][i].iSetE('1');

					cout << "Enter the cost" << endl;
					cin >> temp_double;
					a_table[i][j].iSetC(temp_double);
					a_table[j][i].iSetC(temp_double);

					cout << "Enter the number of flight hours" << endl;
					cin >> temp_int;
					a_table[i][j].iSetH(temp_int);
					a_table[j][i].iSetH(temp_int);

					cout << "Enter the number of the flight minutes" << endl;
					cin >> temp_int;
					a_table[i][j].iSetM(temp_int);
					a_table[j][i].iSetM(temp_int);
				}
				else {

					cout << "Okay,the flight doesnt exist";
					a_table[i][j].iSetE('0');
					a_table[j][i].iSetE('0');
				}

			}
	}

	void Print_table() const//программа для распечатывания нашей матрицы,т.е для того чтобы показать какие существуют полеты
	{//у нашей авиакомпании,куда,за какую стоимость и время 
		for (int i = 0; i < N; i++)
			for (int j = i + 1; j < N; j++) {

				if (a_table[i][j].iGetE() != '0')
				{
					cout << "THE FLIGHT FROM " << a_list[i].cGetN() << " TO " << a_list[j].cGetN() << endl
						<< "IMFORMATION:\n" << "THE FLIGHT COST: ";
					cout << a_table[i][j].iGetC() << " RUB" << endl;
					cout << "THE FLIGHT TIME: " << a_table[i][j].iGetH() << " hours " << a_table[i][j].iGetM() << " minutes" << endl << endl;

				}
			}
	}

	int search_for_number(string c_name)//находит номер города в массиве доступных авиакомпании городов( f <- city name;f- city number in aviacompani cityList)
	{
		int i = 0;
		for (i; i < N; ++i)
			if (a_list[i].cGetN() == c_name)
				return i;
		return -1;
	}

	//если на вход подается 1,то работает Дейкстра,если 2 - Форд-Уэлсон
	void perfectPath(string from, string where, char how, int by = 1)//f<- string "from",string "where",how shuold search : f ->nothing ,but prints the way  
	{//$ % &

		


		vector<int> path;//создали вектор,в который будет выведен весь путь
		int first = search_for_number(from);//номер города в массиве доступных
		int second = search_for_number(where);//номер второго города

		if (first < 0 || second < 0)
		{
			cout << endl << "EROR function \"perfectPath\" : invalid input city name" << endl;
			return;
		}

		switch (by)
		{
		case 1:
			path = shortcut(first, second, how);//получили номера городов которые задействованы в перелете 
			break;
		case 2:
			path = FloydAlghorith(first, second, how);
			break;
		default:
			return;
		}
		int quantity_nodes = 0;
		quantity_nodes = path[path.size() - 1];
		path.pop_back();
		cout << endl << "THE PERFECT WAY IS" << endl;

		for (int i = 0; i < path.size(); i++)
		{
			if (i != (path.size() - 1))
			{
				cout << a_list[path[i]].cGetN() << "--->";
				continue;
			}
			cout << a_list[path[i]].cGetN();
		}
		cout << endl << "THE QUANTITY OF SEARCHED NODES : " << quantity_nodes;
	}

	//обертка для foo все пути рекурсивно
	void allPaths(string name1, string name2, char how) {//функция которая выводи рекурсивно все пути из n1 to n2 и показывает стоимость либо время каждого
		vector<int> path;//создали вектор,в который будет выведен весь путь
		int first = search_for_number(name1);//номер города в массиве доступных
		int second = search_for_number(name2);//номер второго города
		int position = 0;//это переменная,для того чтобы выбрать в каком соотношении нам нужно выбрать time/money для сбалансированного поиска
		multimap<double, vector<int>> mm;//вот это - наш мульти мап,В нем как в словаре будет хранится сумма - путь интовый,который потом мы сможем распечатать 
		if (how == '&') {
			cout << endl << "Time [ | | | | | | | | | ] Money " << endl << "Select a position from 1 to 9" << endl << ">";
			cin >> position;
			while (position < 1 || position>9) {
				cout << "Incorrect value.Try again!" << endl << ">";
				cin >> position;
			}
		}
		
		foo(first, second, path,how,mm,position);
		print_map(mm,how);


	}

	//рекурсивный вывод
	

	void readFromFile(string fileName)
	{
		ifstream fin(fileName);
		double cost;
		int hours, minutes;

		if (!fin.is_open())//если файл не открылся 
		{
			cout << "Uh oh, "<<fileName<<" could not be opened for reading!" << endl;
			return;
		}

		int i, j;
		fin >> i;

		if (i != N)
		{
			cout << "WRONG FILE";
			return;
		}
		else
		{
			fin.seekg(2, ios_base::cur);
			for (int k = 0; k < N; ++k)
			{

				string name;
				getline(fin, name);
				a_list[k].cSetN(name);

			}
		}

		while (!fin.eof())
		{
			fin >> i >> j >> cost >> hours >> minutes;//здесь time это часы.
			a_table[i][j].iSetC(cost); a_table[i][j].iSetH(hours); a_table[i][j].iSetM(minutes); a_table[i][j].iSetE('1');
			a_table[j][i].iSetC(cost); a_table[j][i].iSetH(hours); a_table[j][i].iSetM(minutes); a_table[j][i].iSetE('1');
		}
		fin.close();
	}

	//все рейсы из определенного города
	void allFrom()
	{
		string name;
		cout << "Enter the name of neccessary city" << endl;
		cin >> name;
		name[0] = toupper(name[0]);
		int dt=search_for_number(name);
		while (dt == -1) {
			cout << "Incorrect city name.Try again" << endl;
			name.clear();
			cin >> name;
			name[0] = toupper(name[0]);
			dt = search_for_number(name);
		}
		cout << endl << "ALL FLIGHTS FROM " << name << " : " << endl << "to" << endl;
		int i = search_for_number(name);
		for (int j = 0; j < N; j++) {
			if (a_table[i][j].iGetE() == '1')
			{
				cout << a_list[j].cGetN() << endl;
				cout << a_table[i][j].iGetC() << " RUB" << endl;
				cout << "THE FLIGHT TIME: " << a_table[i][j].iGetH() << " hours " << a_table[i][j].iGetM() << " minutes" << endl << endl;
			}
		}

	}
	
	//все доступные города из определенного города 
	void All_avilable()
	{
		cout << endl << "Available cities:" << endl;
		for (int i = 0; i < N; i++)
		{
			cout << i+1<<". " <<a_list[i].cGetN() << endl;
		}
	}
	int aGetQ() { return N; }

	void add_to_map(multimap<double, vector<int>>& mm, const vector<int> path, char how,int position)
	{
		double cur = 0;
		vector<int> resPath = path;
		switch (how) {
		case '$':
			cur = getPathCost(resPath);
			mm.insert(make_pair(cur, resPath));
			break;
		case '%':
			cur = static_cast<double>(getPathTime(resPath));
			mm.insert(make_pair(cur, resPath));
			break;
		case '&':
			cur = getPathBalance(resPath, position);
			mm.insert(make_pair(cur, resPath));
			break;
		default:
			break;
		}

	}
	void print_map(multimap<double, vector<int>>& mp, char how) {
		multimap<double, vector<int>> ::iterator it = mp.begin();
		switch (how)
		{
		case '&':
			for (int i = 0; it != mp.end(); it++, i++) {
				cout << i+1 << ')' << "\t";
				printPath(it->second);
			}
			break;
		case '$':
			for (int i = 0; it != mp.end(); it++, i++) {
				cout << i+1 << ')' << "\t" << "The flight cost: " << it->first << " RUB" << endl;
				printPath(it->second);
			}
			break;
		case '%':
			for (int i = 0; it != mp.end(); it++, i++) {
				cout << i+1 << ')' << "\t" << "The flight time: " << (static_cast<int>(it->first)) / 60
					<< " hours " << (static_cast<int>(it->first)) % 60 << " minutes" << endl;
				printPath(it->second);
			}
			break;


		}
	}
	void Pathlength(string name1, string name2, int length)
	{
		int from = search_for_number(name1);
		int where = search_for_number(name2);
		multimap<double, vector<int>> mm;
		vector<int> path;
		foo(from, where, path, '$', mm, 0);
		multimap<double, vector<int>>::iterator it = mm.begin();
		cout << "ALL PATHS WITH " << length - 2 << " TRANSFERS" << endl;
		for (int i = 0; it != mm.end();it++) {
			if (it->second.size() == length) {
				cout << i + 1 << ')';
				printPath(it->second);
				i++;
			}
		}
	}
};

void print_menu() {
	system("cls"); // очищаем экран
	cout << "Aviacompany created!What do you want to do?" << endl;
	cout << "1. View all availiable cities " << endl;
	cout << "2. View the flight table" << endl;
	cout << "3. Recieve shortcut from ... to ..." << endl;
	cout << "4. All flights from ..." << endl;
	cout << "5. All paths from ... to ..." << endl;
	cout << "6. All paths length ..." << endl;
	cout << "7. Exit" << endl;
	cout << ">";
}

int get_variant(int count) {
	int variant;
	string s; // строка для считывания введённых данных
	getline(cin, s); // считываем строку

	// пока ввод некорректен, сообщаем об этом и просим повторить его
	while (sscanf(s.c_str(), "%d", &variant) != 1 || variant < 1 || variant > count) {
		cout << "Incorrect input. Try again: "; // выводим сообщение об ошибке
		getline(cin, s); // считываем строку повторно
	}

	return variant;
}

int main()
{ 
	Aviacompany<N> AmericanExpress;
	//AmericanExpress.Filling_table();
	AmericanExpress.readFromFile(static_cast<string>("cppFile.txt"));
	//ВЫВОДИМ В КОНСОЛЬ НАШУ ТАБЛИЦУ ТАК СКАЗАТЬ....//
	//AmericanExpress.Print_table();
	//AmericanExpress.allFrom();
	//дейкстра
	//AmericanExpress.perfectPath(static_cast<string>("Paris"), static_cast<string>("Amsterdam") , '$');	//это кратчайший путь

	//<<<<<<its a foo test boy >>>>>>>>>all paths
	//AmericanExpress.allPaths(static_cast<string>("Paris"), static_cast<string>("Amsterdam"), '%');

	//<<<<<<<<<<its a floyd test boy >>>>>>>
	//AmericanExpress.perfectPath(static_cast<string>("Paris"), static_cast<string>("Amsterdam"), '$',2);
	//AmericanExpress.All_avilable();
	int variant;
	string from, where;
	char how;
	int by, cur;
	
	do {
		print_menu(); // выводим меню на экран

		variant = get_variant(7); // получаем номер выбранного пункта меню

		switch (variant) {
		case 1:
			AmericanExpress.All_avilable();
			break;

		case 2:
			AmericanExpress.Print_table();
			break;

		case 3:
			cout << endl << "What city will you fly from?";
			AmericanExpress.All_avilable();
			cout << endl << ">";
			cin >> cur;
			while (cur<0 || cur >AmericanExpress.aGetQ()) {
				cout << endl << "Incorrect input value.Try again!" << endl << ">";
				cin >> cur;
			}
			from = AmericanExpress.aGetN(cur);
			cout << endl << "What city will you fly?";
			AmericanExpress.All_avilable();
			cout << endl << ">";
			cin >> cur;
			while (cur<0 || cur >AmericanExpress.aGetQ()) {
				cout << endl << "Incorrect input value.Try again!" << endl << ">";
				cin >> cur;
			}
			where= AmericanExpress.aGetN(cur);
			if (where == from) {
				cout << endl << "Congratulations.You're already here!" << endl;
				break;
			}
			cout << endl << "What is the principle of sorting?" << endl << "1. Money     2.Time    3.Balanced by both" << endl << ">";
			cin >>by;
			switch(by){
			case 1:
				how = '$';
				break;
			case 2:
				how = '%';
				break;
			case 3:
				how = '&';
				break;
			default:
				how = '&';
				break;
			}
			cout << "Types of sorting :" << endl << "1.Dijkstra's Algorithm     2.Floyd's Algorithm" << endl << ">";
			cin >> by;
			while (by<1||by>2) {
				cout<<endl<<"Incorrect input value.Try again!" << endl << ">";
				cin >> by;
			}
			AmericanExpress.perfectPath(from, where, how,by);
			from.clear();
			where.clear();
			break;

		case 4:
			AmericanExpress.allFrom();
			break;

		case 5:
			cout << endl << "What city will you fly from?";
			AmericanExpress.All_avilable();
			cout << endl << ">";
			cin >> cur;
			while (cur<0 || cur >AmericanExpress.aGetQ()) {
				cout << endl << "Incorrect input value.Try again!" << endl << ">";
				cin >> cur;
			}
			from = AmericanExpress.aGetN(cur);
			cout << endl << "What city will you fly?" << endl << ">";
			AmericanExpress.All_avilable();
			cout << endl << ">";
			cin >> cur;
			while (cur<0 || cur >AmericanExpress.aGetQ()) {
				cout << endl << "Incorrect input value.Try again!" << endl << ">";
				cin >> cur;
			}
			where = AmericanExpress.aGetN(cur);
			if (where == from) {
				cout << endl << "Congratulations.You're already here!" << endl;
				break;
			}
			cout << endl << "Indicator of interest:" << endl << "1. Money     2.Time    3.Balanced" << endl << ">";
			cin >> by;
			while (by < 1 || by>3) {
				cout << "Incorrect input value.Try again boy!";
				cin >> by;
			}
			switch (by) {
			case 1:
				how = '$';
				break;
			case 2:
				how = '%';
				break;
			case 3:
				how = '&';
				break;
			}
			AmericanExpress.allPaths(from, where, how);
			from.clear();
			where.clear();
			break;
		case 6:
			cout << endl << "What city will you fly from?";
			AmericanExpress.All_avilable();
			cout << endl << ">";
			cin >> cur;
			while (cur<0 || cur >AmericanExpress.aGetQ()) {
				cout << endl << "Incorrect input value.Try again!" << endl << ">";
				cin >> cur;
			}
			from = AmericanExpress.aGetN(cur);
			cout << endl << "What city will you fly?" << endl << ">";
			AmericanExpress.All_avilable();
			cout << endl << ">";
			cin >> cur;
			while (cur<0 || cur >AmericanExpress.aGetQ()) {
				cout << endl << "Incorrect input value.Try again!" << endl << ">";
				cin >> cur;
			}
			where = AmericanExpress.aGetN(cur);
			if (where == from) {
				cout << endl << "Congratulations.You're already here!" << endl;
				break;
			}
			cout << "How many transfers should be in the flight path?" << endl << '>';
			cin >> cur;
			while (cur<0 || cur>AmericanExpress.aGetQ() - 2) 
			{
				cout << "That's imposible!Try again,boy!" << endl << '>';
				cin >> cur;
			}
			AmericanExpress.Pathlength(from, where, cur + 2);
			break;
		}

		if (variant != 7)
			system("pause"); // задерживаем выполнение, чтобы пользователь мог увидеть результат выполнения выбранного пункта
	} while (variant != 7);
	
}