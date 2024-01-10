int hack_it(Keeper& keeper){
	return *(reinterpret_cast<int*>(&keeper) + 1);
}
