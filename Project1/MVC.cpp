#include <iostream>
#include <vector>


namespace MVC
{

// Model: large array of int
// View: We want to show only [start, start+size[
// start and size are saved in Controller
// All connections go through the Controller 

// Model: array of int
class Model { public:
  std::vector<int> m_data;
public:
  Model(std::vector<int> data): m_data(data) { }
  int get(size_t i) const { 
    return m_data[i];
  }
  void update(size_t i, int d) {
    m_data[i] = d;
  }
};

// Controler: intermediate between the View and the Model
class Controller {
  Model* m_model = 0;
  // We want to show only [start, start+size[
  size_t m_startShow = 0;
  size_t m_sizeShow = 3;
public:
  Controller(Model* model) : m_model(model) {}
  // We want to show only [start, start+size[
  std::vector<int> get() const {
    std::vector<int> vec_show(m_sizeShow);
    for (size_t i = 0; i < m_sizeShow; ++i)
      vec_show[i] = m_model->get(i+m_startShow);
    return vec_show;
  }
  // update the data
  void update_model(size_t i, int d) {
    m_model->update(i, d);
  }
  // We want to show only [start, start+size[
  void update_startShow(size_t startShow) { 
    m_startShow = startShow; 
  }
  void update_sizeShow(size_t sizeShow) { 
    m_sizeShow = sizeShow; 
  }
};

// view: show only a part of the vector in Model
class View { 
  // all connections through the Controller
  Controller* m_controller =0;
public:
  View(Model* model) : m_controller(new Controller(model)) { }
  // show : get data from Controler and print
  void show() const {
    std::vector<int> vec_show = m_controller->get();
    for (size_t i = 0; i < vec_show.size(); ++i)
      std::cout << vec_show[i] << " ";
    std::cout << std::endl;
  }
  // update parameters
  void update_model(size_t i, int d) {
    m_controller->update_model(i, d);
  }
  void update_startShow(size_t i, int d) {
    m_controller->update_model(i, d);
  }
  void update_startShow(size_t startShow) {
    m_controller->update_startShow(startShow);
  }
  void update_sizeShow(size_t sizeShow) {
    m_controller->update_sizeShow(sizeShow);
  }
};


int main()
{
  // Create Model (data)
  std::vector<int> data;
  for (size_t i = 0; i < 100; ++i)
    data.push_back((int)i);
  Model* model = new Model(data);
  View viewClient(model);

  // default [0:2]
  viewClient.show();
  viewClient.update_startShow(4);
  viewClient.update_sizeShow(5);
  // [4,5,6 ,7,8]
  viewClient.show();
  viewClient.update_model(6,66);
  // [4,5,66,7,8]
  viewClient.show();
  return 0;
}

}

//int main()
int main_MVC()
{
  return MVC::main();
}
