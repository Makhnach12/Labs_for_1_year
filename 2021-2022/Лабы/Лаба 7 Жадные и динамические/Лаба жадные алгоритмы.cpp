#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct cleaning {
	double rec_time;
	double real_time;
	double eff;
	int num_seq;
};

bool compare(cleaning item1, cleaning item2)
{
	return item1.real_time < item2.real_time;
}

int rounding(int num_1, int num_2)
{
	int num_3;
	num_3 = num_1 / num_2;
	if (num_1 % num_2 > 0)
		num_3++;
	return num_3;
}

int main()
{
	vector <cleaning> cloth;
	double past_time = 0;
	double num_of_cloth, coef;
	double rec_time, real_time;
	vector <pair<int, int>> answer;
	cin >> num_of_cloth >> coef;

	for (int i = 0; i < num_of_cloth; i++){
		cin >> rec_time >> real_time;
		if (rec_time > real_time)
			cloth.insert(cloth.end(), cleaning{ rec_time, real_time, real_time / rec_time, i + 1 });
	}

	sort(cloth.begin(), cloth.end(), compare);

	for (int i = 0; i < cloth.size(); i++){
		if ((cloth[i].rec_time - past_time) / (cloth[i].real_time - past_time) <= coef){
			answer.insert(answer.end(),{ past_time, cloth[i].num_seq });
			past_time += rounding(cloth[i].rec_time - cloth[i].real_time, coef - 1); 
		}
		else{
			cout << "Impossible";
			return 0;
		}
	}

	for (int i = 0; i < cloth.size(); i++) {
		cout << answer[i].first << " " << answer[i].second << "\n";
	}
	  
	cloth.clear();
	return 0;
}