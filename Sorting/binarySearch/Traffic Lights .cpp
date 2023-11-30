/*
There is a street of length ‘X’ with 'X' slots numbered from 0 to 'X' (0,1,…, ’X’). Initially, there are no traffic lights in these slots. Later ‘N’ sets of traffic lights are added to the street one after another. The ‘POS’ array tells the position of the ‘i’th light.
  Your task is to calculate the length of the longest passage without traffic lights after each addition.
  */
vector<int> trafficLights(int n, int x, vector<int> &pos)
{
	set<int> lights;
	multiset<int> distance;

	lights.insert(0);
	lights.insert(x);
	distance.insert(x);

	vector<int> res ;

	for (int i = 0; i < n; ++i)
	{
		int p = pos[i] ;
		set<int>::iterator greaterPos = lights.upper_bound(p);
		set<int>::iterator smallerPos = greaterPos;
		// Shifting the iterator to previous position.
		--smallerPos;

		// Inserting the new distance positions and removing the previous one.
		distance.erase(distance.find(*greaterPos - *smallerPos));
		distance.insert(p - *smallerPos);
		distance.insert(*greaterPos - p);
		lights.insert(p);

		set<int>::iterator ans = distance.end();
		--ans;
		res.push_back(*ans) ;
	}

	return res ;
}
