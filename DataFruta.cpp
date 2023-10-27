#include <iostream>
#include <string>
#include <vector>

using namespace std;
/*
A função funciona comparando primeiro os anos das duas datas.
Se o ano da primeira data for menor que o ano da segunda data,então a primeira data é menor que a segunda data. 
Se as duas datas tiverem o mesmo ano,então a função compara os meses das duas datas.
Se o mês da primeira data for menor que o mês da segunda data,então a primeira data é menor que a segunda data.
Se as duas datas tiverem o mesmo mês,então a função compara os dias das duas datas.
Se o dia da primeira data for menor que o dia da segunda data, então a primeira data é menor que a segunda data.
*/
class Data
{
	int dia, mes, ano;

public:
	static int compara(Data d1, Data d2)
	{
		if (d1.ano < d2.ano || (d1.ano == d2.ano && (d1.mes < d2.mes || (d1.mes == d2.mes && d1.dia < d2.dia))))
		{
			return -1;
		}
		else if (d1.ano == d2.ano && d1.mes == d2.mes && d1.dia == d2.dia)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}

	Data(int _dia, int _mes, int _ano)
	{
		dia = _dia;
		mes = _mes;
		ano = _ano;
	}
	string toString()
	{
		string ret = "";
		ret.append(to_string(dia));
		ret.append("/");
		ret.append(to_string(mes));
		ret.append("/");
		ret.append(to_string(ano));
		return ret;
	}
};

class Lista
{
public:
	virtual void entradaDeDados() = 0;
	virtual void mostraMediana() = 0;
	virtual void mostraMenor() = 0;
	virtual void mostraMaior() = 0;
};

class ListaNomes
{
	vector<string> lista;

public:
	void entradaDeDados()
	{
		lista.push_back("Teste");
	}

	void mostraMediana()
	{
		cout << "Aqui vai mostrar a mediana da lista de strings" << endl;
	}

	void mostraMenor()
	{
		cout << "Aqui vai mostrar o primeiro nome alfabeticamente" << endl;
	}
	void mostraMaior()
	{
		cout << "aqui vai mostrar o ultimo nome alfabeticamente" << endl;
	}
};

class ListaDatas
{
	vector<Data> lista;
	vector<Data> lista;

public:
	void entradaDeDados()
	{
		cout << "Quantas datas na lista: ";
		int n;
		cin >> n;

		for (int i = 0; i < n; i++)
		{
			int dia, mes, ano;
			cout << "Digite a data " << i + 1 << " (dia mes ano): ";
			cin >> dia >> mes >> ano;
			Data data(dia, mes, ano);
			lista.push_back(data);
		}
	}

	void mostraMediana()
	{
		if (lista.empty())
		{
			cout << "A lista de datas esta vazia." << endl;
		}
		else
		{
			sort(lista.begin(), lista.end(), [](Data d1, Data d2)
				 { return Data::compara(d1, d2) == -1; });

			int meio = lista.size() / 2;
			cout << "Mediana da lista de datas: " << lista[meio].toString() << endl;
		}
	};

	class ListaSalarios
	{
		vector<float> lista;

	public:
		void entradaDeDados()
		{
		}

		void mostraMediana()
		{
			cout << "Aqui vai mostrar a mediana da lista de salarios" << endl;
		}

		void mostraMenor()
		{
			cout << "Aqui vai mostrar o menor dos salarios" << endl;
		}
		void mostraMaior()
		{
			cout << "aqui vai mostrar o maior dos salarios" << endl;
		}
	};

	class ListaIdades
	{
		vector<int> lista;

	public:
		void entradaDeDados()
		{
		}

		void mostraMediana()
		{
			cout << "Aqui vai mostrar a mediana da lista de idades" << endl;
		}

		void mostraMenor()
		{
			cout << "Aqui vai mostrar a menor das idades" << endl;
		}
		void mostraMaior()
		{
			cout << "aqui vai mostrar a maior das idades" << endl;
		}
	};

	int main()
	{	
		system ("cls");
		vector<Lista *> listaDeListas;

		ListaNomes listaNomes;
		listaNomes.entradaDeDados();
		listaDeListas.push_back(&listaNomes);

		ListaDatas listaDatas;
		listaDatas.entradaDeDados();
		listaDeListas.push_back(&listaDatas);

		ListaSalarios listaSalarios;
		listaSalarios.entradaDeDados();
		listaDeListas.push_back(&listaSalarios);

		ListaIdades listaIdades;
		listaIdades.entradaDeDados();
		listaDeListas.push_back(&listaIdades);

		for (Lista *l : listaDeListas)
		{
			l->mostraMediana();
			l->mostraMenor();
			l->mostraMaior();
		}
	}
