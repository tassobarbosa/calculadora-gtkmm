#include<gtkmm.h>
#include<iostream>

using namespace Gtk;

Window * pWindow;
Entry * txtResult;
Button * btn9, * btn8,* btn7,* btn6,* btn5,* btn4,* btn3,* btn2,* btn1,* btn0;
Button * btnDevide, * btnTimes, *btnMinus, *btnPlus, * btnDot, * btnEqual, * btnClean;

double number1 = 0;
double number2 = 0;
double result = 0;
int which_operation = 0;

void on_btn9_clicked(){
  std::string screen = txtResult->get_text();
  screen+="9";
  txtResult->set_text(screen);
}
void on_btn8_clicked(){
  std::string screen = txtResult->get_text();
  screen+="8";
  txtResult->set_text(screen);
}
void on_btn7_clicked(){
  std::string screen = txtResult->get_text();
  screen+="7";
  txtResult->set_text(screen);
}
void on_btn6_clicked(){
  std::string screen = txtResult->get_text();
  screen+="6";
  txtResult->set_text(screen);
}
void on_btn5_clicked(){
  std::string screen = txtResult->get_text();
  screen+="5";
  txtResult->set_text(screen);
}
void on_btn4_clicked(){
  std::string screen = txtResult->get_text();
  screen+="4";
  txtResult->set_text(screen);
}
void on_btn3_clicked(){
  std::string screen = txtResult->get_text();
  screen+="3";
  txtResult->set_text(screen);
}
void on_btn2_clicked(){
  std::string screen = txtResult->get_text();
  screen+="2";
  txtResult->set_text(screen);
}
void on_btn1_clicked(){
  std::string screen = txtResult->get_text();
  screen+="1";
  txtResult->set_text(screen);
}
void on_btn0_clicked(){
  std::string screen = txtResult->get_text();
  screen+="0";
  txtResult->set_text(screen);
}
void on_btnClean_clicked(){
  std::string screen = txtResult->get_text();
  screen = "";
  txtResult->set_text(screen);
  number1 = number2 = result = which_operation = 0;
}

void on_btnPlus_clicked(){
  std::string screen_number = txtResult->get_text();
  which_operation = 1;
  number1 = std::stoi(screen_number);
  screen_number="";
  txtResult->set_text(screen_number);
}

void on_btnMinus_clicked(){
  std::string screen_number = txtResult->get_text();
  which_operation = 2;
  number1 = std::stoi(screen_number);
  screen_number="";
  txtResult->set_text(screen_number);
}
void on_btnTimes_clicked(){
  std::string screen_number = txtResult->get_text();
  which_operation = 3;
  number1 = std::stoi(screen_number);
  screen_number="";
  txtResult->set_text(screen_number);
}
void on_btnDevide_clicked(){
  std::string screen_number = txtResult->get_text();
  which_operation = 4;
  number1 = std::stoi(screen_number);
  screen_number="";
  txtResult->set_text(screen_number);
}
void on_btnEqual_clicked(){
  std::string screen_number = txtResult->get_text();

  number2 = std::stoi(screen_number);
  if(which_operation == 1) result = number1 + number2;
  if(which_operation == 2) result = number1 - number2;
  if(which_operation == 3) result = number1 * number2;
  if(which_operation == 4) result = number1 / number2;

  number1 = number2 = 0;

  txtResult->set_text(std::to_string(result));
}

int main(int argc, char **argv){

  auto app = Application::create(argc, argv, "org.gtkmm.calculadora");
  auto refBuilder = Builder::create();

  refBuilder-> add_from_file("calculadora.glade");
  refBuilder-> get_widget("window", pWindow);
//Button * btnDot;
  if(pWindow){
    refBuilder-> get_widget("btn9", btn9);
    refBuilder-> get_widget("btn8", btn8);
    refBuilder-> get_widget("btn7", btn7);
    refBuilder-> get_widget("btn6", btn6);
    refBuilder-> get_widget("btn5", btn5);
    refBuilder-> get_widget("btn4", btn4);
    refBuilder-> get_widget("btn3", btn3);
    refBuilder-> get_widget("btn2", btn2);
    refBuilder-> get_widget("btn1", btn1);
    refBuilder-> get_widget("btn0", btn0);
    refBuilder-> get_widget("txtResult", txtResult);
    refBuilder-> get_widget("btnClean", btnClean);
    refBuilder-> get_widget("btnPlus", btnPlus);
    refBuilder-> get_widget("btnMinus", btnMinus);
    refBuilder-> get_widget("btnTimes", btnTimes);
    refBuilder-> get_widget("btnDevide", btnDevide);
    refBuilder-> get_widget("btnEqual", btnEqual);
  }


  if(btn9){
    btn9->signal_clicked().connect(sigc::ptr_fun(on_btn9_clicked));
  }
  if(btn8){
    btn8->signal_clicked().connect(sigc::ptr_fun(on_btn8_clicked));
  }
  if(btn7){
    btn7->signal_clicked().connect(sigc::ptr_fun(on_btn7_clicked));
  }
  if(btn6){
    btn6->signal_clicked().connect(sigc::ptr_fun(on_btn6_clicked));
  }
  if(btn5){
    btn5->signal_clicked().connect(sigc::ptr_fun(on_btn5_clicked));
  }
  if(btn4){
    btn4->signal_clicked().connect(sigc::ptr_fun(on_btn4_clicked));
  }
  if(btn3){
    btn3->signal_clicked().connect(sigc::ptr_fun(on_btn3_clicked));
  }
  if(btn2){
    btn2->signal_clicked().connect(sigc::ptr_fun(on_btn2_clicked));
  }
  if(btn1){
    btn1->signal_clicked().connect(sigc::ptr_fun(on_btn1_clicked));
  }
  if(btn0){
    btn0->signal_clicked().connect(sigc::ptr_fun(on_btn0_clicked));
  }
  if(btnClean){
    btnClean->signal_clicked().connect(sigc::ptr_fun(on_btnClean_clicked));
  }
  if(btnPlus){
    btnPlus->signal_clicked().connect(sigc::ptr_fun(on_btnPlus_clicked));
  }
  if(btnMinus){
    btnMinus->signal_clicked().connect(sigc::ptr_fun(on_btnMinus_clicked));
  }
  if(btnTimes){
    btnTimes->signal_clicked().connect(sigc::ptr_fun(on_btnTimes_clicked));
  }
  if(btnDevide){
    btnDevide->signal_clicked().connect(sigc::ptr_fun(on_btnDevide_clicked));
  }
  if(btnEqual){
    btnEqual->signal_clicked().connect(sigc::ptr_fun(on_btnEqual_clicked));
  }

  app->run (*pWindow);
  delete pWindow;
  return 0;
}


//g++ calculadora.cpp -o calculadora $(pkg-config gtkmm-3.0 --cflags --libs) -export-dynamic
