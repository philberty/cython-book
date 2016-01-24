from flask import Flask
from flask import jsonify

app = Flask("DashboardExample")
dashboard = None

@app.route("/")
def status():
    return jsonify(dashboard.roster.client_list())

class Dashboard:
    
    _port = None
    _roster = None

    def __init__(self, port, roster):
        global dashboard
        self._port = port
        self._roster = roster
        dashboard = self

    @property
    def port(self):
        return self._port

    @property
    def roster(self):
        return self._roster

    def start(self):
        app.run(port=self.port)


if __name__ == "__main__":
    Dashboard(8080, None).start()
