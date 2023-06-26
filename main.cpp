#include <iostream>
#include <vector>

class pair{
public:
	int x;
	int y;

	pair(){}

	pair(int a,int b){
		x = a;
		y = b;
	}

	~pair(){
		free(this);
	}

	int abs_diff(){
		int r = x-y;
		if(r < 0){
			return -r;
		}
		return r;
	}

	void print(){

		std::string s = "";
		s.append("(");
		s.append(std::to_string(x));
		s.append(",");
		s.append(std::to_string(y));
		s.append(")");
		std::cout << s << "\n";

	}

};

pair* smallest_diff(std::vector<int>& a,std::vector<int>& b,std::vector<pair*>& a_mod,std::vector<pair*>& b_mod);

void set_list(std::vector<int>& x,std::vector<pair*>& x_mod,int k);

void quick_sort(int strt,int end,std::vector<pair*> &v);
int partition(int strt,int end,std::vector<pair*> &v);

int main()
{
	 /* ?\n;||(or) e &&(and)*/

	//std::vector<pair> c;
	std::vector<int> a = {1,3,15,11,2};
	std::vector<int> b = {23,127,235,19,8};


	std::vector<pair*> a_mod;
	std::vector<pair*> b_mod;

	/*set_list(a,a_mod,1);
	for(int i = 0;i < a_mod.size();i++){
		std::cout << a_mod[i].x << "\n";
	}*/
	pair* min = smallest_diff(a,b,a_mod,b_mod);
	min->print();
	delete(min);




	std::cout << "---------" << "\n";





	return 0;
}


int partition(int strt,int end,std::vector<pair*> &v){

	int pivot = v[(strt+end)/2]->x;

	while(strt <= end){

		while(v[strt]->x < pivot){
			strt++;
		}
		while(v[end]->x > pivot){
			end--;
		}
		if(strt <= end){
			std::swap(v[strt]->x,v[end]->x);
			strt++;
			end--;
		}
	}
	return strt;
}

void quick_sort(int strt,int end,std::vector<pair*> &v){

	int point = partition(strt,end,v);

	if(strt < point-1){
		quick_sort(strt,point-1,v);
	}
	if(point < end){
		quick_sort(point+1,end,v);
	}

}

void set_list(std::vector<int>& x,std::vector<pair*>& x_mod,int k){

	//pair p = pair();
	for(int i = 0;i < x.size();i++){
		pair* p = new pair(x[i],k);
		x_mod.push_back(p);
	}

}


pair* smallest_diff(std::vector<int>& a,std::vector<int>& b,std::vector<pair*>& a_mod,std::vector<pair*>& b_mod){



	pair* min =new  pair();

	set_list(a,a_mod,1);
	set_list(b,b_mod,0);


	a_mod.insert(a_mod.end(),b_mod.begin(),b_mod.end());
	quick_sort(0,a_mod.size()-1,a_mod);//O((n+m)log(n+m)),average

	int min_diff = a_mod[a_mod.size()-1]->x;

	for(int i = 0;i < a_mod.size()-1;i++){

		if(a_mod[i]->y == a_mod[i+1]->y){
			continue;
		}
		pair* p = new pair(a_mod[i]->x,a_mod[i+1]->x);
		if(min_diff >= p->abs_diff()){
			min_diff = p->abs_diff();
			min = p;
		}

	}

	return min;
}


