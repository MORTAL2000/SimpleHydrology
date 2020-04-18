struct Plant{
  Plant(int i, glm::ivec2 d){
    index = i;
    pos = glm::vec2(i/d.y, i%d.y);
  };

  Plant(glm::vec2 p, glm::ivec2 d){
    pos = p;
    index = (int)p.x*d.y+(int)p.y;
  };

  glm::vec2 pos;
  int index;
  float size = 0.5;
  const float maxsize = 1.0;
  const float rate = 0.05;

  void grow();

  Plant& operator=(const Plant& o){
    if(this != &o){  //Self Check
      pos = o.pos;
      index = o.index;
      size = o.size;
    }
    return *this;
  };
};


void Plant::grow(){
  size += rate*(maxsize-size);
};