# Introduction #

A Gateway file is an XML file containing basic information about potential network hosts. The most important part is a list of possible IP addresses for hosts.


# Schema v0.7 #

```
<?xml version="1.0" encoding="UTF-8"?>
<xs:schema xmlns:xs="http://www.w3.org/2001/XMLSchema"
targetNamespace="http://wyspr.s4t4n.net/gateway"
xmlns="http://wyspr.s4t4n.net/gateway"
elementFormDefault="qualified">
	<xs:element name="gateway">
		<xs:complexType>
			<xs:sequence maxOccurs="1" minOccurs="1">
				<xs:element name="meta" maxOccurs="1" minOccurs="1">
					<xs:complexType>
						<xs:sequence maxOccurs="1" minOccurs="1">
							<xs:element name="name" type="xs:normalizedString" />
							<xs:element name="description" type="xs:string" />
							<xs:element name="website">
								<xs:complexType>
									<xs:sequence maxOccurs="1" minOccurs="1">
										<xs:element name="name" type="xs:normalizedString" />
										<xs:element name="url" type="xs:anyURI" />
										<xs:any minOccurs="0" maxOccurs="unbounded" />
									</xs:sequence>
								</xs:complexType>
							</xs:element>
							<xs:element name="location">
								<xs:complexType>
									<xs:sequence maxOccurs="1" minOccurs="1">
										<xs:element name="primary" type="xs:anyURI" />
										<xs:element name="alternatives" maxOccurs="1" minOccurs="0">
											<xs:complexType>
												<xs:sequence maxOccurs="1" minOccurs="0">
													<xs:element name="url" type="xs:anyURI" maxOccurs="unbounded" minOccurs="0"/>
												</xs:sequence>
											</xs:complexType>
										</xs:element>
									</xs:sequence>
								</xs:complexType>
							</xs:element>
							<xs:element name="tags" maxOccurs="1" minOccurs="0">
								<xs:complexType>
									<xs:sequence maxOccurs="1" minOccurs="1">
										<xs:element name="tag" type="xs:token" minOccurs="0" maxOccurs="unbounded" />
									</xs:sequence>
								</xs:complexType>
							</xs:element>
						</xs:sequence>
					</xs:complexType>
				</xs:element>
				<xs:element name="hosts" maxOccurs="1" minOccurs="1">
					<xs:complexType>
						<xs:sequence>
							<xs:element name="host" minOccurs="1" maxOccurs="unbounded">
								<xs:complexType>
									<xs:sequence>
										<xs:element name="ip">
											<xs:simpleType>
												<xs:restriction base="xs:string">
													<xs:pattern value="([0-9]?[0-9]?[0-9][.]){3}([0-9]?[0-9]?[0-9])" />
												</xs:restriction>
											</xs:simpleType>
										</xs:element>
										<xs:any minOccurs="0" maxOccurs="unbounded" />
									</xs:sequence>
									<xs:attribute name="id" type="xs:token" use="required" />
								</xs:complexType>
							</xs:element>
						</xs:sequence>
					</xs:complexType>
				</xs:element>
			</xs:sequence>
		</xs:complexType>
	</xs:element>
</xs:schema>
```

# Example File #

```
<?xml version="1.0" encoding="UTF-8"?>
<gateway xmlns="http://wyspr.s4t4n.net/gateway" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xsi:schemaLocation="http://wyspr.s4t4n.net/gateway http://wyspr.s4t4n.net/gateway/wyspr-gateway_0.1.xsd">
	<meta>
		<name>Name Of The Chat</name>
		<description>Here is a short description of what the chat is about.</description>
		<website><!-- Primary associated website of the chat -->
			<name>Name of the Site</name>
			<url>URL of the website</url>
		</website>
		<location><!-- Location of this file -->
			<primary>http://www.example.com/file.xml</primary>
			<alternatives>
				<url>http://www.example.com/alt1.xml</url>
				<url>http://www.example.com/alt2.xml</url>
			</alternatives>
		</location>
		<tags>
			<tag>some</tag>
			<tag>keywords</tag>
		</tags>
	</meta>
	<hosts>
		<host id="PotentialHost">
			<ip>127.0.0.1</ip>
		</host>
		<host id="user123">
			<ip>172.65.123.89</ip>
		</host>
		<host id="AnotherHost">
			<ip>67.0.28.4</ip>
		</host>
		<host id="SomeHost">
			<ip>27.3.2.8</ip>
		</host>
	</hosts>
</gateway>
```