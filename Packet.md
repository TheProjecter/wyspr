# Introduction #

There are many different [packet types](PacketTypes.md) used in the Wyspr protocol. All of them are based on the same XML-based template. This wiki entry provides the schema for that template, and some example packets. See the page '[PacketTypes](PacketTypes.md)', of the Packet Types file in the downloads section, for more details on specific packet types.


# Schema v0.3 #

```
<?xml version="1.0" encoding="UTF-8"?>
<xs:schema xmlns:xs="http://www.w3.org/2001/XMLSchema"
targetNamespace="http://wyspr.s4t4n.net/packet"
xmlns="http://wyspr.s4t4n.net/packet"
elementFormDefault="qualified">
	<xs:element name="packet">
		<xs:complexType>
			<xs:sequence maxOccurs="1" minOccurs="1">
				<xs:element name="data" maxOccurs="1" minOccurs="1">
					<xs:complexType>
						<xs:sequence>
							<xs:any minOccurs="0" maxOccurs="unbounded" processContents="lax" />
						</xs:sequence>
					</xs:complexType>
				</xs:element>
			</xs:sequence>
			<xs:attribute name="type" type="xs:string" use="required" />
		</xs:complexType>
	</xs:element>
</xs:schema>
```

# Schema v0.4 #

```
<?xml version="1.0" encoding="UTF-8"?>
<xs:schema xmlns:xs="http://www.w3.org/2001/XMLSchema"
targetNamespace="http://wyspr.s4t4n.net/packet"
xmlns="http://wyspr.s4t4n.net/packet"
elementFormDefault="qualified">
	<xs:element name="packet">
		<xs:complexType>
			<xs:sequence maxOccurs="1" minOccurs="1">
				<xs:element name="data" maxOccurs="1" minOccurs="0">
					<xs:complexType>
						<xs:sequence>
							<xs:element name="d" minOccurs="0" maxOccurs="unbounded">
								<xs:complexType>
									<xs:simpleContent>
										<xs:extension base="xs:string">
											<xs:attribute name="type" type="xs:token" use="required" />
										</xs:extension>
									</xs:simpleContent>
								</xs:complexType>
							</xs:element>
						</xs:sequence>
					</xs:complexType>
				</xs:element>
			</xs:sequence>
			<xs:attribute name="type" type="xs:string" use="required" />
		</xs:complexType>
	</xs:element>
</xs:schema>
```

# Example '[echo](echo.md)' Packet #

```
<?xml version="1.0" encoding="UTF-8"?>
<packet type="echo" xmlns="http://wyspr.s4t4n.net/packet" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xsi:schemaLocation="http://wyspr.s4t4n.net/packet http://wyspr.s4t4n.net/packet/wyspr-packet_0.2.xsd">
	<data>
		<d type="origin">GameFreak7744</d>
		<d type="content">This message goes out to everybody connected!</d>
	</data>
</packet>
```