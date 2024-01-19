#pragma once

class ICommand {
public:
	virtual void Execute() const = 0;
};