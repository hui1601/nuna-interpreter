#include <cwchar>

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

std::vector<int64_t> st;
int main() {
  setlocale(LC_ALL, "");
  while (true) {
    if(feof(stdin)) break;
    size_t i, input_len;
    int64_t back, num;
    std::wstring input;
    getline(std::wcin, input);
    input_len = input.length();
    for (i = 0; i < input_len; i++) {
      const wchar_t now = input[i];
      const size_t ind = i;
      bool flag = false;
      num = 1;
      // 숫자 처리
      if (i + 1 != input_len && input[i + 1] == L'.') {  //.의 갯수
        i++;
        num = 0;
        while (i < input_len && input[i] == L'.') {
          i++;
          num++;
        }
        i--;
        flag = true;
//        std::wcout << L"테스트 " << input[i + 1] << "\n";
      }
      if (i + 1 != input_len && input[i + 1] == L'으') { // 이전 값
        if (st.size() <= 1) {
          std::wcerr << L"\n키워드 '으'에서 스택의 크기가 2보다 작습니다.(" << i << ")\n";
          break;
        }
        if(!flag) num = st[st.size() - 2];
        else num += st[st.size() - 2];
        i++;
      }
      if (now == L'흐') {
        if(input[i + 1] != L'읏') {
          std::wcerr << L"\n키워드 '흐'는 '읏'으로 끝나야 합니다.(" << i << ", " << now << ")\n";
          break;
        }
        i++;
        if(num == 0) st[st.size() - 1] = 0;
        else st[st.size() - 1] = pow(st.back(), num);
      }
      else if (now == L'누' || now == L'눈') {
        st.push_back(num);
      } else if (now == L'💕') {
        if (st.empty()) {
          std::wcerr << L"\n스택이 비어있습니다.(" << ind << ", " << now << ")\n";
          break;
        }
        back = st.back();
        st.pop_back();
        if (st.empty()) {
          std::wcerr << L"\n스택이 비어있습니다.(" << ind << ", " << now << ")\n";
          break;
        }
        back += st.back();
        st.pop_back();
        st.push_back(back);
      } else if (now == L'응') {
        if (st.empty()) {
          std::wcerr << L"\n스택이 비어있습니다.(" << ind << ", " << now << ")\n";
          break;
        }
        back = -st.back();
        st.pop_back();
        if (st.empty()) {
          std::wcerr << L"\n스택이 비어있습니다.(" << ind << ", " << now << ")\n";
          break;
        }
        back += st.back();
        st.pop_back();
        st.push_back(back);
      } else if (now == L'!') {
        for (int64_t j : st) {
          std::wcout << (wchar_t)j;
        }
        std::wcout << L"\n";
//        std::wcout << L"### DEBUG STACK PRINT ###\n[";
//        for (int64_t j : st) {
//            std::wcout << j << L", ";
//        }
//        std::wcout << L"]\n";
      } else if (now == L'헤') {
        if (st.empty()) {
          std::wcerr << L"\n스택이 비어있습니다.(" << ind << ", " << now << ")\n";
          break;
        }
        st.pop_back();
      } else if (now == L'.' || now == L'읏');
      else {
        if (st.empty()) {
          std::wcerr << L"\n스택이 비어있습니다.(" << ind << ", " << now << ")\n";
          break;
        }
        back = st.back();
        st.pop_back();
//        std::wcout << L"CHECK " << back << L" " << num << L"\n";
        if (now == L'나' || now == L'난')
          st.push_back((int64_t)back * num);
        else if (now == L'주' || now == L'죽')
          st.push_back(back - num);
        else if (now == L'거')
          st.push_back(back + num);
        else {
          std::wcerr << L"\n예기치 못한 문자가 있습니다.(" << i << ", " << now << ")\n";
          break;
        }
      }
    }
  }
  return 0;
}