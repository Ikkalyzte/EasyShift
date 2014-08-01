#ifndef PRGMSTATE_INCLUDED
#define PRGMSTATE_INCLUDED

//Different possible states
enum PrgmState {
	background,
	creation,
	personCreation,
	personCreationError,
	shiftCreation,
	shiftCreationError,
	eventCreation,
	eventCreationError,
	personDeletion,
	shiftDeletion,
	eventDeletion
};

inline PrgmState& operator--(PrgmState& state) {
	switch (state) {
	case personCreation: return state = creation;
	case personCreationError: return state = personCreation;
	case shiftCreation: return state = creation;
	case shiftCreationError: return state = shiftCreation;
	case eventCreation: return state = creation;
	case eventCreationError: return state = eventCreation;
	default: return state = background;
	}
}

inline PrgmState& operator++(PrgmState& state) {
	switch (state) {
	case personCreation: return state = personCreationError;
	case shiftCreation: return state = shiftCreationError;
	case eventCreation: return state = eventCreationError;
	default: return state = background;
	}
}

#endif