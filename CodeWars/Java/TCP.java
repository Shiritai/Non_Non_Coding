package Java;

import java.util.ArrayList;
import java.util.HashMap;

public class TCP {
    static enum INPUT {
        APP_PASSIVE_OPEN, APP_ACTIVE_OPEN, APP_SEND, 
        APP_CLOSE, APP_TIMEOUT, RCV_SYN, 
        RCV_ACK, RCV_SYN_ACK, RCV_FIN, RCV_FIN_ACK;
    }

    static enum STATE {
        CLOSED(0), LISTEN(1), SYN_SENT(2), SYN_RCVD(3), 
        ESTABLISHED(4), CLOSE_WAIT(5), LAST_ACK(6), 
        FIN_WAIT_1(7), FIN_WAIT_2(8), CLOSING(9), 
        TIME_WAIT(10), ERROR(11);
        final int value;
        private STATE(int value){ this.value = value; }
    }


    public static String traverseStates(String[] events) {
        var state = STATE.CLOSED;
        var maps = new ArrayList<HashMap<INPUT, STATE>>(STATE.values().length);
        for (int i = 0; i < STATE.values().length; ++i){
            maps.add(new HashMap<INPUT, STATE>());
        }
        maps.get(STATE.CLOSED.value).put(INPUT.APP_PASSIVE_OPEN, STATE.LISTEN);
        maps.get(STATE.CLOSED.value).put(INPUT.APP_ACTIVE_OPEN, STATE.SYN_SENT);
        maps.get(STATE.LISTEN.value).put(INPUT.RCV_SYN, STATE.SYN_RCVD);
        maps.get(STATE.LISTEN.value).put(INPUT.APP_SEND, STATE.SYN_SENT);
        maps.get(STATE.LISTEN.value).put(INPUT.APP_CLOSE, STATE.CLOSED);
        maps.get(STATE.SYN_RCVD.value).put(INPUT.APP_CLOSE, STATE.FIN_WAIT_1);
        maps.get(STATE.SYN_RCVD.value).put(INPUT.RCV_ACK, STATE.ESTABLISHED);
        maps.get(STATE.SYN_SENT.value).put(INPUT.RCV_SYN, STATE.SYN_RCVD);
        maps.get(STATE.SYN_SENT.value).put(INPUT.RCV_SYN_ACK, STATE.ESTABLISHED);
        maps.get(STATE.SYN_SENT.value).put(INPUT.APP_CLOSE, STATE.CLOSED);
        maps.get(STATE.ESTABLISHED.value).put(INPUT.APP_CLOSE, STATE.FIN_WAIT_1);
        maps.get(STATE.ESTABLISHED.value).put(INPUT.RCV_FIN, STATE.CLOSE_WAIT);
        maps.get(STATE.FIN_WAIT_1.value).put(INPUT.RCV_FIN, STATE.CLOSING);
        maps.get(STATE.FIN_WAIT_1.value).put(INPUT.RCV_FIN_ACK, STATE.TIME_WAIT);
        maps.get(STATE.FIN_WAIT_1.value).put(INPUT.RCV_ACK, STATE.FIN_WAIT_2);
        maps.get(STATE.CLOSING.value).put(INPUT.RCV_ACK, STATE.TIME_WAIT);
        maps.get(STATE.FIN_WAIT_2.value).put(INPUT.RCV_FIN, STATE.TIME_WAIT);
        maps.get(STATE.TIME_WAIT.value).put(INPUT.APP_TIMEOUT, STATE.CLOSED);
        maps.get(STATE.CLOSE_WAIT.value).put(INPUT.APP_CLOSE, STATE.LAST_ACK);
        maps.get(STATE.LAST_ACK.value).put(INPUT.RCV_ACK, STATE.CLOSED);
        for (var e : events){
            state = maps.get(state.value).get(INPUT.valueOf(e));
            if (state == null){
                return STATE.ERROR.toString();
            }
        }
        return state.toString();
    }

    public static void main(String [] args){
        System.out.println(traverseStates(new String[] {"APP_ACTIVE_OPEN","RCV_SYN_ACK","RCV_FIN"}));
        System.out.println(traverseStates(new String[] {"APP_PASSIVE_OPEN", "RCV_SYN","RCV_ACK"}));
        System.out.println(traverseStates(new String[] {"APP_ACTIVE_OPEN","RCV_SYN_ACK","RCV_FIN","APP_CLOSE"}));
        System.out.println(traverseStates(new String[] {"APP_ACTIVE_OPEN"}));
        System.out.println(traverseStates(new String[] {"APP_PASSIVE_OPEN","RCV_SYN","RCV_ACK","APP_CLOSE","APP_SEND"}));
    }
}