#pragma once
#ifndef ISCROLLABLE_INCLUDED
#define ISCROLLABLE_INCLUDED


class IScrollable
{
public:
	IScrollable(void);
	virtual void scroll(int) = 0;
	virtual ~IScrollable(void) = 0;
};

#endif