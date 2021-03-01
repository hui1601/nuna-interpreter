#include <string>
#include <iostream>
#include <stack>
#include <wchar.h>
#include <vector>
std::vector <int64_t> st;
int main(){
    setlocale(LC_ALL, "");
    while (true){
        size_t i, input_len, num;
        int64_t back;
        std::wstring input;
        getline(std::wcin, input);
        input_len = input.length();
        for(i = 0; i < input_len; i++){
            const wchar_t now = input[i];
            const int ind = i;
            num = 1;
            if(i + 1 != input_len && input[i + 1] == L'.'){//.의 갯수
                i++;
                num = 0;
                while (i < input_len && input[i] == L'.'){
                    i++;
                    num++;
                }
                i--;
            }
            if(now == L'누' || now == L'눈'){
                st.push_back(num);
            }else if(now == L'💕'){
                if(st.empty()){
                    std::wcout << L"\n스택이 비어있습니다.(" << ind << ")\n";
                    break;
                }
                back = st.back();
                st.pop_back();
                if(st.empty()){
                    std::wcout << L"\n스택이 비어있습니다.(" << ind << ")\n";
                    break;
                }
                back += st.back();
                std::wcout << st.back() << L"\n";
                st.pop_back();
                st.push_back(back);
            }else if(now == L'🏩'){
                if(st.empty()){
                    std::wcout << L"\n스택이 비어있습니다.(" << ind << ")\n";
                    break;
                }
                back = -st.back();
                st.pop_back();
                if(st.empty()){
                    std::wcout << L"\n스택이 비어있습니다.(" << ind << ")\n";
                    break;
                }
                back += st.back();
                st.pop_back();
                st.push_back(back);
            }else if(now == L'!'){
                for(int j = 0; j < st.size(); j++){
                    std::wcout << (wchar_t)st[j];
                }
                std::wcout << L"\n";
            }else {
                if(st.empty()){
                    std::wcout << L"\n스택이 비어있습니다.(" << ind << ")\n";
                    break;
                }
                back = st.back();
                st.pop_back();
                if(now == L'나') st.push_back(back * num);
                else if(now == L'주') st.push_back(back - num);
                else if(now == L'거') st.push_back(back + num);
                else {
                    std::wcout << L"\n예기치 못한 문자가 있습니다.(" << i << ", " << now << ")\n";
                    break;
                }
            }
        }
    }
    return 0;
}