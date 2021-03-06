#include <wchar.h>

#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <math.h>
std::vector<int64_t> st;
int main() {
  setlocale(LC_ALL, "");
  while (true) {
    if(feof(stdin)) break;
    size_t i, input_len, num;
    int64_t back;
    std::wstring input;
    getline(std::wcin, input);
    input_len = input.length();
    for (i = 0; i < input_len; i++) {
      const wchar_t now = input[i];
      const int ind = i;
      num = 1;
      if (i + 1 != input_len && input[i + 1] == L'.') {  //.의 갯수
        i++;
        num = 0;
        while (i < input_len && input[i] == L'.') {
          i++;
          num++;
        }
        i--;
      } else if (i + 1 != input_len && input[i + 1] == L'으') {
        if (st.size() <= 1) {
          std::wcerr << L"\n키워드 '으'에서 스택의 크기가 2보다 작습니다.("
                     << ind << ")\n";
          break;
        }
        num = st[st.size() - 2];
        i++;
      } else if (i + 1 != input_len && input[i + 1] == L'흐') {
        i += 2;
        num = 0;
        while (i < input_len && input[i] == L'.') {
          i++;
          num++;
        }
        if(input[i] != L'읏') {
          std::wcerr << L"\n키워드 '흐'는 '읏'으로 끝나야 합니다.("
                     << ind << ")\n";
          break;
        }
        num = pow(2, num);
      }
      if (now == L'누' || now == L'눈') {
        if(input[i] == L'으') num = st.back();
        st.push_back(num);
      } else if (now == L'💕') {
        if (st.empty()) {
          std::wcerr << L"\n스택이 비어있습니다.(" << ind << ")\n";
          break;
        }
        back = st.back();
        st.pop_back();
        if (st.empty()) {
          std::wcerr << L"\n스택이 비어있습니다.(" << ind << ")\n";
          break;
        }
        back += st.back();
        st.pop_back();
        st.push_back(back);
      } else if (now == L'응') {
        if (st.empty()) {
          std::wcerr << L"\n스택이 비어있습니다.(" << ind << ")\n";
          break;
        }
        back = -st.back();
        st.pop_back();
        if (st.empty()) {
          std::wcerr << L"\n스택이 비어있습니다.(" << ind << ")\n";
          break;
        }
        back += st.back();
        st.pop_back();
        st.push_back(back);
      } else if (now == L'!') {
        for (int j = 0; j < st.size(); j++) {
          std::wcout << (wchar_t)st[j];
        }
        std::wcout << L"\n";
      } else if (now == L'헤') {
        if (st.empty()) {
          std::wcerr << L"\n스택이 비어있습니다.(" << ind << ")\n";
          break;
        }
        st.pop_back();
      } else {
        if (st.empty()) {
          std::wcerr << L"\n스택이 비어있습니다.(" << ind << ")\n";
          break;
        }
        back = st.back();
        st.pop_back();
        if (now == L'나' || now == L'난')
          st.push_back(back * num);
        else if (now == L'주' || now == L'죽')
          st.push_back(back - num);
        else if (now == L'거')
          st.push_back(back + num);
        else {
          std::wcerr << L"\n예기치 못한 문자가 있습니다.(" << i << ", " << now
                     << ")\n";
          break;
        }
      }
    }
  }
  return 0;
}