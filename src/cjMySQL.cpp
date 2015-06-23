#include "cjMySQL.h"

namespace cj {

	//--------------------------------------------------------------------------------------------------
	//----------          class MySQL          ---------------------------------------------------------
	//--------------------------------------------------------------------------------------------------
	MySQL::MySQL() {
		conn = NULL;
		res = NULL;
		fields = NULL;
	}
	MySQL::~MySQL() {
		if (res != NULL) mysql_free_result(res);
		if (conn != NULL) mysql_close(conn);
	}
	bool MySQL::init() {
		conn = mysql_init(NULL);
		if (conn == NULL) {
			application->logger_out("Error: can't create MySQL-descriptor");
			return false;
		}
		application->logger_out("MySQL-descriptor was created!");
		return true;
	}
	bool MySQL::connect(String host, String user, String password, String db) {
		application->logger_out("MySQL connect");
		try {
			string host8 = host.toString8();
			string user8 = user.toString8();
			string pswd8 = password.toString8();
			string db8 = db.toString8();
			if (!mysql_real_connect(conn, host.toString8().c_str(), user.toString8().c_str(), password.toString8().c_str(), db.toString8().c_str(), NULL, NULL, 0)) {
				String error = mysql_error(conn);
				application->logger_out("Error: can't connect to database");
				return false;
			}
		}
		catch (...) {
			application->logger_out("connect catch");
			return false;
		}
		application->logger_out("Connected to database!");
		return true;
	}
	bool MySQL::query(String sql) {
		if (res != NULL) mysql_free_result(res);
		if (mysql_query(conn, sql.toString8().c_str()) != 0) {
			application->logger_out("Error: mistake in SQL");
			return false;
		}
		return true;
	}
	bool MySQL::exec(String sql) {
		if (mysql_query(conn, sql.toString8().c_str()) != 0)
		{
			return false;
		}
		return true;
	}
	int MySQL::active(String sql) {
		if (exec(sql)) {
			if (storeResult()) {
				int count = getRowCount();
				return count;
			}
		}
		return 0;
	}
	bool MySQL::storeResult() {
		if (res != NULL) mysql_free_result(res);
		res = mysql_store_result(conn);
		fields = mysql_fetch_fields(res);
		if (res) return true;
		return false;
	}
	void MySQL::freeResult() {
		if (res != NULL) mysql_free_result(res);
		res = NULL;
		fields = NULL;
	}
	String MySQL::getEscapeString(String s) {
		int len = s.getLength();
		char *res = (char*)malloc(len * 2 + 1);
		//MYSQL *mysql, char *to,const char *from, unsigned long length
		mysql_real_escape_string(conn, res, s.toString8().c_str(), len);
		String sRes = res;
		free(res);

		return sRes;
	}
	String MySQL::getEscapeString(char *s, int len) {
		char *res = (char*)malloc(len * 2 + 1);
		//MYSQL *mysql, char *to,const char *from, unsigned long length
		mysql_real_escape_string(conn, res, s, len);
		String sRes = res;
		free(res);

		return sRes;
	}
	int MySQL::getRowCount() {
		return mysql_num_rows(res);
	}
	int MySQL::getFieldCount() {
		int count = mysql_num_fields(res);
		return count;
	}
	String MySQL::getFieldValue(int rowIndex, int fieldIndex) {
		mysql_data_seek(res, rowIndex);
		MYSQL_ROW row = mysql_fetch_row(res);
		if (row[fieldIndex] == NULL) return "";
		return (String)row[fieldIndex];
	}
	String MySQL::getFieldValue(int rowIndex, String fieldName) {
		//	MYSQL_ROW row = mysql_fetch_row(res);
		int count = mysql_num_fields(res);
		for (int i = 0; i < count; i++) {
			if (fieldName == (String)fields[i].name) {
				return getFieldValue(rowIndex, i);
			}
		}
		return "";
	}
	String MySQL::getLastId() {
		String sql = "select LAST_INSERT_ID();";
		if (this->exec(sql)) {
			if (this->storeResult()) {
				int count = this->getRowCount();
				if (count > 0) {
					String lastSiteId = this->getFieldValue(0, "LAST_INSERT_ID()");
					return lastSiteId;
				}
			}
		}
		return "";
	}

}
