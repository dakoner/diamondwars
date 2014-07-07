class Killable {
  public:
    Killable(): _dead(false) {
    }

    void kill() {
      _dead = true;
    }
    
    bool dead() {
      return _dead;
    }

  private:
    bool _dead;
};
