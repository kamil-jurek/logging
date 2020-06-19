#pragma once

class Investment
{
  public:
    Investment();
    Investment(int value_);
    Investment(const Investment&);

    virtual ~Investment();

    int getValue() const;

  protected:
    int value;
};