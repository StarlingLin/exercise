import java.util.concurrent.atomic.AtomicInteger;

public class Ticket {
    private static final AtomicInteger remainingTickets = new AtomicInteger(1000);
    public static void main(String[] args) {
        for (int i = 1; i <= 5; i++) {
            new Thread(new TicketThread(i)).start();
        }
    }
    static class TicketThread implements Runnable {
        private final int i;
        public TicketThread(int threadId) {
            this.i = threadId;
        }
        @Override
        public void run() {
            while (true) {
                int currentTicket = remainingTickets.getAndDecrement();
                if (currentTicket <= 0) {
                    break;
                }
                System.out.printf("%d__%d%n", i, currentTicket);
            }
        }
    }
}