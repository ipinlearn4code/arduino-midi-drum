Core

router ospf 1
 router-id 1.1.1.1
 network 123.13.11.8 0.0.0.3 area 0
 network 172.11.55.4 0.0.0.3 area 0
 network 200.125.12.4 0.0.0.3 area 0



Arjuna

router ospf 1
 router-id 4.4.4.4
 network 125.12.25.12 0.0.0.3 area 0
 network 172.11.55.4 0.0.0.3 area 0
 network 110.123.123.0 0.0.0.7 area 0


Svc

router ospf 1
 router-id 3.3.3.3
 network 125.12.25.12 0.0.0.3 area 0
 network 123.13.11.8 0.0.0.3 area 0
 network 100.100.100.0 0.0.0.7 area 0



Gayo

router ospf 1
 router-id 2.2.2.2
 network 125.12.25.12 0.0.0.3 area 0
 network 123.13.11.8 0.0.0.3 area 0
 network 10.10.10.0 0.0.0.3 area 0
