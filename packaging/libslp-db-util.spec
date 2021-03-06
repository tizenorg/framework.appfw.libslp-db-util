Name:       libslp-db-util
Summary:    DB Utility
Version:    0.1.1
Release:    0
Group:      System/Libraries
License:    Apache License, Version 2.0
Source0:    %{name}-%{version}.tar.gz
Requires(post): /sbin/ldconfig
Requires(postun): /sbin/ldconfig
BuildRequires:  cmake
BuildRequires:  pkgconfig(sqlite3)
BuildRequires:  pkgconfig(dlog)
BuildRequires:  pkgconfig(glib-2.0)
BuildRequires:  pkgconfig(icu-i18n)

%description

%package devel
Summary:    Devel package for libslp-db-util (devel)
Group:      Development/Libraries
Requires:   %{name} = %{version}-%{release}

%description devel

%prep
%setup -q -n %{name}-%{version}

%build
cmake . -DCMAKE_INSTALL_PREFIX=%{_prefix}

make %{?jobs:-j%jobs}

%install
rm -rf %{buildroot}
%make_install

%post
/sbin/ldconfig
if [ ! -d /opt/dbspace ]
then
        mkdir -p /opt/dbspace
fi
chown :5000 /opt/dbspace
chmod 775 /opt/dbspace

%postun -p /sbin/ldconfig

%files
%defattr(-,root,root,-)
%{_libdir}/libSLP-db-util.so
%{_libdir}/libSLP-db-util.so.0
%{_libdir}/libSLP-db-util.so.0.1.0

%files devel
%defattr(-,root,root,-)
%{_includedir}/db-util/*.h
%{_libdir}/pkgconfig/db-util.pc

