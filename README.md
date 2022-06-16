# CPPPhysicsEngine
## A c++ physics engine intergrated with the verlet function
## Special thanks and documentation
*This was all just to learn and get started on c++ and learning to make physics stuff. This wouldn't not have been possible without [@johnBuffer](https://github.com/johnBuffer) and his videos. Go Check him out and his [videos](https://www.youtube.com/c/PezzzasWork)*

*Thank you to [@johnBuffer](https://github.com/johnBuffer) for the event manager, [check it out here](https://github.com/johnBuffer/SFML-EventManager)*

*This engine uses SFML 2.5.1 64 bit. Find and read the documents of [SFML here](https://www.sfml-dev.org/)*

## To get started
**You want to include these in your main cpp file**
- SFML/Graphics.h
- EventManager.h
- Solver.h
- Container.h



**In your main cpp file create a new class, like this**
```cpp
class Solver : public sol::Solver {
public:
  Solver(sf::RenderWindow& window, sfev::EventManager& eventManager, con::Container container, size_t subSteps) : sol::Solver(window, eventManager, container, subSteps) {}
  
  virtual Load() {
    // Do stuff in here when loading everything
  }
  
  virtual void Update() {
    // Do stuff in here every frame before rendering
  }
  
  virtual void Render() {
    // This is where you want to Window.draw(drawable) all of your things
  }
  
  virtual void Play() {
    // Play sounds in the queue **Queue not implemented yet**
  }
};
```

**Then in your main function you can use the new class**
```cpp
int main() {
  sf::RenderWindow window(sf::VideoMode(1080, 720), "Test"); // This is the SFML RenderWindow that we will use to render/draw things
  
  sfev::EventManager evm(window, true); // The EventManager is used to manage and use the SFML window events such as mouse event and key events and etc.
  
  evm.addEventCallback(sf::Event::EventType::Closed, [&](const sf::Event&) {window.close(); }); // This closes the window when the window closed event gets called
  
  con::Container container; // This is the container where we will store pointers to all of the Circles, Polygons, Sounds, Drawables, etc etc.
  
  sol::Solver* solver = new Solver(window, evm, container, subSteps);
  solver->Run();
  
  return 0;
}
```
