#ifndef EINCOMPLETTE_H
#define EINCOMPLETTE_H
#include <QString>

class EIncomplette {
  protected :
      QString Str;
  public:
      EIncomplette(QString _Str){Str = _Str;}
      QString getString(){return Str;}
  };


#endif // EINCOMPLETTE_H
