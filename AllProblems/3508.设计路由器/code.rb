class Router

=begin
    :type memory_limit: Integer
=end
    def initialize(memory_limit)
        
    end


=begin
    :type source: Integer
    :type destination: Integer
    :type timestamp: Integer
    :rtype: Boolean
=end
    def add_packet(source, destination, timestamp)
        
    end


=begin
    :rtype: Integer[]
=end
    def forward_packet()
        
    end


=begin
    :type destination: Integer
    :type start_time: Integer
    :type end_time: Integer
    :rtype: Integer
=end
    def get_count(destination, start_time, end_time)
        
    end


end

# Your Router object will be instantiated and called as such:
# obj = Router.new(memory_limit)
# param_1 = obj.add_packet(source, destination, timestamp)
# param_2 = obj.forward_packet()
# param_3 = obj.get_count(destination, start_time, end_time)