#pragma once

#include "core.h"
using namespace core;

namespace mysql {

#include <mysqlconn.h>

#ifdef OS_WINDOWS
	#pragma comment (lib, "libmysql.lib")
#endif


	class MySQL : public Object {
		MYSQL *conn;
		MYSQL_RES *res;
		MYSQL_FIELD *fields;
	public:
		MySQL();
		~MySQL();
		virtual bool init();
		virtual bool connect(String host, String user, String password, String db);
		virtual bool query(String sql);
		virtual bool exec(String sql);
		virtual int active(String sql);
		virtual bool storeResult();
		virtual void freeResult();

		virtual String getEscapeString(String s);
		virtual String getEscapeString(char *s, int len);

		virtual int getRowCount();
		virtual int getFieldCount();
		virtual String getFieldValue(int rowIndex, int fieldIndex);
		virtual String getFieldValue(int rowIndex, String fieldName);

		virtual int getLastId();
	};

}
