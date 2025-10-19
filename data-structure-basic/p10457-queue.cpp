#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	deque<char> group[13];
	char card[55];
	vector<char> opened;
	int count[13]={0};
    unordered_map<char, int> card_to_group;  // 牌面→堆编号（0~12）
    card_to_group['A'] = 0;
    card_to_group['2'] = 1;
    card_to_group['3'] = 2;
    card_to_group['4'] = 3;
    card_to_group['5'] = 4;
    card_to_group['6'] = 5;
    card_to_group['7'] = 6;
    card_to_group['8'] = 7;
    card_to_group['9'] = 8;
    card_to_group['0'] = 9;  // 10用0表示
    card_to_group['J'] = 10;
    card_to_group['Q'] = 11;
    card_to_group['K'] = 12;

	for(int i=0;i<13;i++){
		for(int j=0;j<4;j++){
			char c;
			cin>>c;
			group[i].push_back(c);
		}
	}

	//life 12
	int life=4;
	int card_index=12;
	int couple=0;
	while (life>0)
	{
		char card1;
		if(card_index!=12){
			if (group[card_index].empty()) break;
			card1=group[card_index].back();
			group[card_index].pop_back();
		}else{
			//life card
			if (group[card_index].empty()) break;  // 生命牌堆空，结束
			card1=group[card_index].front();
			group[card_index].pop_front();
		}

		if (card1=='K')
		{
			life--;
			card_index = 12;
			continue;
		}

		group[card_to_group[card1]].push_front(card1);
		count[card_to_group[card1]]++;
		if(count[card_to_group[card1]]==4){
			couple++;
		}
		
		card_index=card_to_group[card1];
	}

	cout<<couple<<'\n';
	

}