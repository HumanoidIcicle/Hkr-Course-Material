# Energy-aware Routing in WSN
- Every node is a router and data source
- Nodes are resource constrained
- WSN is resilient to failure of individual nodes

> ***Energy aware routing in WSN is a techinque to optimize data transmission path to conserve energy and extend lifetime of sensor nodes by selecting routes based on energy levels and thereby minimizing power consumption.***

- Communication is most expensive, the goals with energy aware routing are:
    - Shortest hop
    - Lowest energy route
    - Lowest routing overhead

## Routing Strategies
They define how sensor nodes communicate and forward data to sink node efficiently while conserving energy.

### Stateless routing
Nodes forward packets without using routing tables or network state.

- ***Flooding***: Broadcast packets to all neighbours until delivery or hop-limit expires. High redundancy.

- ***Gossiping***: Node forwards packets to one randomly selected neighbour.Better than flooding as reduces redundancy. Reduces overhead.

- ***Geographic***:Forward packet to destination location, needs position info.

- ***Epidemic***: Pairwise message exchange, handles partitions. Requires buffering which is costly in WSN.


### Proactive Routing
Maintains up to data routing information at alltimes through periodic updates.

***Application***
- Used in real-time monitoring where immediate data delivery is required.

***Properties***
- Does not scale to large networks.

### Reactive Routing
Establishes routes only when data needs to be transmitted.

***Application*** 
- Used in event driven WSNs e.g intrusion detection.

***Properties***
- Routes are created and cached as needed.
- High latency, lower resource demand.

### Datacentric Routing
Routing based on data. The sink queries specific data and only matching nodes respond, reducing energy consumption.

- Energy efficient: No redundant transmissions.
- Scalable: Efficient in large networks.

***Application***
- Environmental monitoring system: temp, pollution, fire detection
- Military surveillance: intrusion and movement detection
